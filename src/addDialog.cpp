#include "../header/addDialog.h"
#include "../ui/ui_addDialog.h"

addDialog::addDialog(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::display() {
    //TODO
}