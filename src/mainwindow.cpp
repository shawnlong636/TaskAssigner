#include "../header/mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include "../header/task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isRoot = false; // isRoot always initialized with False. Set to true in main.cpp only

    // Disable editing of table
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    activeRow = -1;
    rootTask = new Task("Root");
}

MainWindow::~MainWindow()
{
    delete ui;
    if (isRoot)
        delete rootTask;
    if (add)
        delete add;
    if (edit)
        delete edit;
    if (rmv)
        delete rmv;
}

void MainWindow::setIsRoot(bool isRoot) {
    this->isRoot = isRoot;
}

void MainWindow::setRootTask(Task* task)
{
    delete rootTask;
    rootTask = task;
}

void MainWindow::on_addButton_clicked()
{
    add = new addDialog(this);
    add->display();
    connect(add,&addDialog::sendTaskData, this, &MainWindow::receiveNewTask );
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    activeRow = row;
}

void MainWindow::on_editButton_clicked()
{
    QTableWidget* table = ui->tableWidget;
    // Can't edit if there is nothing to edit or if no row is active yet
    if(table->rowCount() < 1 || activeRow == -1)
    {
        return;
    }
    Task* activeTask = rootTask->getSubtaskAt(activeRow);

    editDialog* edit = new editDialog(this);
    edit->show();
    connect(edit, &editDialog::sendTaskData, this, &MainWindow::receiveExistingTask);
    connect(this, &MainWindow::pushCurrentSettings,edit,&editDialog::receiveCurrentTask);

    QString name = QString::fromStdString(activeTask->getName());
    QString desc = QString::fromStdString(activeTask->getDescription());
    QDate date = activeTask->getQDate();
    CompletionState* state = activeTask->getState();
    emit pushCurrentSettings(name,desc,date,*state);
}

void MainWindow::on_removeButton_clicked()
{
    QTableWidget* table = ui->tableWidget;

    // Can't remove if there is nothing to remove or if no row is active yet
    if(table->rowCount() < 1 || activeRow == -1)
    {
        return;
    }

    removeDialog* remove = new removeDialog(this, rootTask, activeRow);
    remove->display();

    connect(remove, &removeDialog::sendRowToRemove, this, &MainWindow::receiveRemoveTask );

    // Removed handled in receiveRemoveTask()
}

void MainWindow::on_showButton_clicked()
{
    QTableWidget* table = ui->tableWidget;

    // Can't show subtasks if there are no tasks at all or if no row is active yet
    if(table->rowCount() < 1 || activeRow == -1)
    {
        return;
    }

    Task* shownSubtask = rootTask->getSubtaskAt(activeRow);
    if(shownSubtask)
    {
        QString windowTitle = "Subtasks (" + QString::fromStdString(shownSubtask->getName()) + ")";
        if (this->parent() == nullptr)
            this->setWindowTitle("Task Assigner (Main)");

        MainWindow* window = new MainWindow(this);
        window->move(this->pos().x()+20,this->pos().y()+20);
        window->setWindowTitle(windowTitle);

        // Must set appropriate rootTask
        window->setRootTask(shownSubtask);

        QTableWidget* subtask_table = window->ui->tableWidget;

        // Loop through subtasks to populate new table
        int row = 0;

        for(auto i = 0; i < shownSubtask->getNumOfSubtasks(); ++i)
        {
            subtask_table->insertRow(row);

            Task* currentSubTask = shownSubtask->getSubtaskAt(i);

            subtask_table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(currentSubTask->getName())));
            subtask_table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(currentSubTask->getDescription())));
            subtask_table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(currentSubTask->getDate())));
            subtask_table->setItem(row, 3, new QTableWidgetItem("Incomplete"));

            ++row;
        }

        window->show();
    }
}


void MainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionExport_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save File as"),QDir::homePath(),tr("Tab-delimitted (*.txt)")  );

    std::ofstream ofs(filename.toStdString());

    ofs << "Parent\tName\tDescription\tDate\tStatus\n";

    for (int i = 0; i<rootTask->getNumOfSubtasks(); i++) {
        ofs << "\t" << rootTask->getSubtaskAt(i)->toDo();
    }
    ofs.close();
}

void MainWindow::on_actionAbout_triggered()
{
    QString str = "This program is a final project by Yuval Bar, Shawn Long, and Arzhang Valadhkani for CS 100 at the University of California, Riverside.\nEnjoy!";
    QMessageBox::about(this,tr("About"),str);
}

void MainWindow::receiveNewTask(const QString& taskName, const QString& description, const QDate& dueDate) {

    QTableWidget* table = ui->tableWidget;

    // Add row after activeRow, if no row is active add first row
    int row = activeRow > -1 ? activeRow + 1 : 0;

    // Create new task and add to root
    Task* addedTask = new Task(taskName,description,dueDate);
    rootTask->addSubtask(addedTask, row);

    table->insertRow(row);

    // Setting name
    table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(addedTask->getName())));

    // Setting description
    table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(addedTask->getDescription())));

    // Setting due date
    table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(addedTask->getDate())));

    // Setting completion status
    table->setItem(row, 3, new QTableWidgetItem("Incomplete"));
}

void MainWindow::receiveRemoveTask(int row)
{
    QTableWidget* table = ui->tableWidget;

    rootTask->removeSubtaskAt(row);
    table->removeRow(row);

    // Inactivate activeRow in case removed all rows below currently selected row
    if(table->rowCount() - 1 < activeRow)
    {
        activeRow = -1;
    }
}

void MainWindow::receiveExistingTask(const QString& taskName, const QString& description, const QDate& dueDate, const QString& state) {
    QTableWidget* table = ui->tableWidget;
    // Can't edit if there is nothing to edit or if no row is active yet
    if(table->rowCount() < 1 || activeRow == -1)
    {
        return;
    }
    Task* activeTask = rootTask->getSubtaskAt(activeRow);

    activeTask = rootTask->getSubtaskAt(activeRow);
    activeTask->setName(taskName.toStdString());
    activeTask->setDescription(description.toStdString());
    activeTask->setQDate(dueDate);


    if (state.toStdString() =="complete") {
        activeTask->changeState(new Complete(activeTask));
        table->setItem(activeRow,3, new QTableWidgetItem(QString::fromStdString("Complete")));
    }

    else if (state.toStdString()=="incomplete") {
        activeTask->changeState(new Incomplete(activeTask));
        table->setItem(activeRow,3, new QTableWidgetItem(QString::fromStdString("Incomplete")));
    }

    else {
         activeTask->changeState(new InProgress(activeTask));
         table->setItem(activeRow,3, new QTableWidgetItem(QString::fromStdString("In Progress")));
    }


    table->setItem(activeRow, 0, new QTableWidgetItem(QString::fromStdString(activeTask->getName())));
    table->setItem(activeRow, 1, new QTableWidgetItem(QString::fromStdString(activeTask->getDescription())));
    table->setItem(activeRow, 2, new QTableWidgetItem(QString::fromStdString(activeTask->getDate())));

}

