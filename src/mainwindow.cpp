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
    table->setRowCount(table->rowCount() + 1);

    if(table->columnCount() == 0)
    {
        table->setColumnCount(1);
    }

    // Setting name
    table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Task name"));

    // Setting description
    table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem("Description"));

    // Setting due date
    table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem("Due date"));
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
}
