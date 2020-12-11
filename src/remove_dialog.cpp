#include "../header/remove_dialog.h"
#include "../ui/ui_remove_dialog.h"

Remove_Dialog::Remove_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remove_Dialog)
{
    ui->setupUi(this);
}

Remove_Dialog::~Remove_Dialog()
{
    delete ui;
}
