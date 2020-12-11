#include "../header/removeDialog.h"
#include "../ui/ui_removeDialog.h"
#include "../header/task.h"

removeDialog::removeDialog(QWidget *parent, Task* rootTask, int activeRow) :
    Dialog(parent),
    ui(new Ui::removeDialog)
{
    ui->setupUi(this);
    ui->label->setText("Are you sure you want to remove " + QString::fromStdString(rootTask->getSubtaskAt(activeRow)->getName()) + "?");

    row = activeRow;
}

removeDialog::~removeDialog()
{
    delete ui;
}

void removeDialog::display() {
    show();
}

void removeDialog::on_buttonBox_rejected()
{
    close();
}

void removeDialog::on_buttonBox_accepted()
{
    emit sendRowToRemove(row);
    close();
}
