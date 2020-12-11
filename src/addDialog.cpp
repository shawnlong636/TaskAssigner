#include "../header/addDialog.h"
#include "../ui/ui_addDialog.h"

addDialog::addDialog(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    ui->dateField->setDate(QDate::currentDate());
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::display() {
    // opens the ui for Add Strategy
    this->show();
}

void addDialog::on_buttonBox_accepted()
{
    QString name = ui->nameField->toPlainText();
    QString desc = ui->descField->toPlainText();
    QDate date = ui->dateField->date();

    emit sendTaskData(name,desc,date);
    this->close();
}

void addDialog::on_buttonBox_rejected()
{
    this->close();
}
