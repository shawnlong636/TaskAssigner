#include "../header/removeDialog.h"
#include "../ui/ui_removeDialog.h"
#include "../header/task.h"

removeDialog::removeDialog(QWidget *parent, Task* taskToRemove) :
    Dialog(parent),
    ui(new Ui::removeDialog)
{
    ui->setupUi(this);

    focusedTask = taskToRemove;

    ui->label->setText("Are you sure you want to remove " + QString::fromStdString(focusedTask->getName()) + "?");
}

removeDialog::~removeDialog()
{
    delete ui;
}

void removeDialog::display() {
    show();
}
