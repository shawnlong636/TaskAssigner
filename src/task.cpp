#include "../header/task.h"

bool Task::checkCompletion()
{
    // TODO: Return value based on completionState
    return true;    // Place holder
}

void Task::toDo()
{
    // TODO: PrintToDo based on completionState
}

void Task::changeState(CompletionState* state) {
    if (this->state != nullptr)
        delete state;
    this->state = state;
}
/* MOCK FUNCTIONS NEEDED FOR TESTING STATE METHODS */
void Task::setName(std::string name) {
    // this->taskName = QString::fromStdString(name);
}
void Task::setDescription(std::string desc) {
    this->description = QString::fromStdString(desc);
}
void Task::setDate(std::string date) {
    if (this->dueDate != nullptr)
        delete dueDate;
    this->dueDate = new QDate(QDate::fromString(QString::fromStdString(date), "mm-dd-yyyy"));
}