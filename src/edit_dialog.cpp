#include "../header/edit_dialog.h"
#include "../ui/ui_edit_dialog.h"

Edit_Dialog::Edit_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Dialog)
{
    ui->setupUi(this);
}

Edit_Dialog::~Edit_Dialog()
{
    delete ui;
}

void Edit_Dialog::implementAction()
{
    //Getting the input from each textbox in QString form
       QString qstr = ui->lineTask->text();
       QString qstr1 = ui->lineDescription->text();
       QString qstr2 = ui->dateInput->date().toString("dd/MM/yyyy");
       QDate d(QDate::fromString(qstr2,"dd/MM/yyyy"));


       //Converting the inputs to strings
       std::string name = qstr.toStdString();
       std::string description = qstr1.toStdString();
       //converting the date input to QDate object and setting it equal to day month and year

       int day = d.day();
       int month = d.month();
       int year  = d.year();

       //Setting it up to the task object
       input->setDate(year, month, day);
       input->setDescription(description);
       input->setName(name);


}


