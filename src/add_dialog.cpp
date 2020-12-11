#include "../header/add_dialog.h"
#include "../ui/ui_add_dialog.h"

Add_Dialog::Add_Dialog(QWidget *parent) :
    QDialog(parent), Dialog(),
    ui(new Ui::Add_Dialog)
{
    ui->setupUi(this);
    ui->dateEdit;
}


Add_Dialog::~Add_Dialog()
{
    delete ui;
}
 void Add_Dialog::implementAction()
{   //Getting the input from each textbox in QString form
    QString qstr = ui->lineEdit->text();
    QString qstr1 = ui->lineEdit_2->text();
    QString qstr2 = ui->dateEdit->date().toString("dd/MM/yyyy");
    QDate d(QDate::fromString(qstr2,"dd/MM/yyyy"));

    //Converting the inputs to strings
    std::string name = qstr.toStdString();
    std::string description = qstr1.toStdString();

    int day = d.day();
    int month = d.month();
    int year  = d.year();


    //Setting it up to the task object
    input->setDate(year, month, day);
    input->setDescription(description);
    input->setName(name);

    emit transferData(qstr, qstr1, qstr2);
    //passing it up to the row now
   // table->insertRow(r);
   // table->setItem(r, 0, new QTableWidgetItem(qstr));
   // table->setItem(r, 1, new QTableWidgetItem(qstr1));
   // table->setItem(r, 2, new QTableWidgetItem(qstr2));
   }

void Add_Dialog::set_task(Task* t)
{
    this->input = t;

}
Task* Add_Dialog::get_task()
{
    return input;
}
