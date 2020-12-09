#include "../header/mainwindow.h"
#include "../ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable editing of table
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    activeRow = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// TODO: Create window prompting user to input name, description and due date
void MainWindow::on_addButton_clicked()
{
    // As an example, simply adds rows for now
    QTableWidget* table = ui->tableWidget;

    // Add row after activeRow, if no row is active add first row
    int row = activeRow > -1 ? activeRow + 1 : 0;

    table->insertRow(row);

    // Setting name
    table->setItem(row, 0, new QTableWidgetItem("Task name"));

    // Setting description
    table->setItem(row, 1, new QTableWidgetItem("Description"));

    // Setting due date
    table->setItem(row, 2, new QTableWidgetItem("Due date"));
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

    table->setItem(activeRow, 0, new QTableWidgetItem("Edited"));
    table->setItem(activeRow, 1, new QTableWidgetItem("Edited"));
    table->setItem(activeRow, 2, new QTableWidgetItem("Edited"));
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

void MainWindow::on_showButton_clicked()
{
    // TODO: CHANGE THIS REF TO THE PARENT TASK NAME
    QString windowTitle = "Subtasks (<task_name>)";
    if (this->parent() == nullptr)
        this->setWindowTitle("Task Assigner (Main)");

    MainWindow* window = new MainWindow(this);
    window->move(this->pos().x()+20,this->pos().y()+20);
    window->setWindowTitle(windowTitle);

    // TODO: Populate subtasks in window before showing
    QTableWidget* subtask_table = window->ui->tableWidget;

    int row = 0;
    // Loop through parent task
    subtask_table->insertRow(row);
    subtask_table->setItem(row, 0, new QTableWidgetItem("Dummy Subtask"));
    subtask_table->setItem(row, 1, new QTableWidgetItem("Dummy Subtask"));
    subtask_table->setItem(row, 2, new QTableWidgetItem("Dummy Duedate"));

    window->show();
}
