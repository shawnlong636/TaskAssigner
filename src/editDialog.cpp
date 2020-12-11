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
    // opens the ui for Add Strategy
    show();
}

void editDialog::receiveCurrentTask(const QString& name, const QString& desc, const QDate& date, const CompletionState& state) {
    ui->nameField->setText(name);
    ui->descField->setText(desc);
    ui->dateField->setDate(date);
    this->taskName = name;
    this->description = desc;
    this->dueDate = date;
    this->state = QString::fromStdString(state.toStr());
    if (state.toStr()=="complete")
        ui->completeButton->setChecked(true);
    else if (state.toStr()=="incomplete")
        ui->incompleteButton->setChecked(true);
    else
        ui->inProgressButton->setChecked(true);
}

void editDialog::on_buttonBox_accepted()
{
    taskName = ui->nameField->toPlainText();
    description = ui->descField->toPlainText();
    dueDate = ui->dateField->date();

    if (ui->completeButton->isChecked()) {
        state = "complete";
    }
    else if (ui->incompleteButton->isChecked()) {
        state = "incomplete";
    }
    else {
        state = "inprogress";
    }

    emit sendTaskData(taskName,description,dueDate,state);
    this->close();
}

void editDialog::on_buttonBox_rejected()
{
    this->close();
}
