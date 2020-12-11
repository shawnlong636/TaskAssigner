#include "../header/editDialog.h"
#include "../ui/ui_editDialog.h"

editDialog::editDialog(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::editDialog)
{
    ui->setupUi(this);
}

editDialog::~editDialog()
{
    delete ui;
}

void editDialog::display() {
    // TODO
}