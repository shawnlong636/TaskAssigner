#include "../header/mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include "../header/task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable editing of table
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    activeRow = -1;
    rootTask = new Task("Root");
}

// TODO: Delete rootTask here only if this is the root window!
MainWindow::~MainWindow()
{
    delete ui;
}

// TODO: Create window prompting user to input name, description and due date
void MainWindow::on_addButton_clicked()
{
    // As an example, simply adds rows for now
    QTableWidget* table = ui->tableWidget;

    // Create new task and add to root
    Task* addedTask = new Task();
    rootTask->addSubtask(addedTask);

    // Add row after activeRow, if no row is active add first row
    int row = activeRow > -1 ? activeRow + 1 : 0;

    table->insertRow(row);

    // Setting name
    table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(addedTask->getName())));

    // Setting description
    table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(addedTask->getDescription())));

    // Setting due date
    table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(addedTask->getDate())));
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    activeRow = row;
}

// TODO: Create window prompting user to input name, description and due date
void MainWindow::on_editButton_clicked()
{
    QTableWidget* table = ui->tableWidget;

    // Can't edit if there is nothing to edit or if no row is active yet
    if(table->rowCount() < 1 || activeRow == -1)
    {
        return;
    }

    Task* activeTask = rootTask->getSubtaskAt(activeRow);
    activeTask->setName("Edited Name");
    activeTask->setDescription("Edited Description");
    activeTask->setDate(2021,1,1);

    table->setItem(activeRow, 0, new QTableWidgetItem(QString::fromStdString(activeTask->getName())));
    table->setItem(activeRow, 1, new QTableWidgetItem(QString::fromStdString(activeTask->getDescription())));
    table->setItem(activeRow, 2, new QTableWidgetItem(QString::fromStdString(activeTask->getDate())));
}

// TODO: Add confirmation Dialog window before removing
void MainWindow::on_removeButton_clicked()
{
    QTableWidget* table = ui->tableWidget;

    // Can't remove if there is nothing to remove or if no row is active yet
    if(table->rowCount() < 1 || activeRow == -1)
    {
        return;
    }

    table->removeRow(activeRow);

    // Inactivate activeRow in case removed all rows below currently selected row
    if(table->rowCount() - 1 < activeRow)
    {
        activeRow = -1;
    }
}
