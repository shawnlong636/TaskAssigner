#include "../header/removeDialog.h"
#include "../ui/ui_removeDialog.h"

removeDialog::removeDialog(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::removeDialog)
{
    ui->setupUi(this);
}

removeDialog::~removeDialog()
{
    delete ui;
}

void removeDialog::display() {
    // TODO
}
