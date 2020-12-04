#include "../header/mainwindow.h"
#include "../ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable editing of table
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    activeRow = 0;
    activeColumn = 0;
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

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{
    activeRow = row;
    activeColumn = column;
}
