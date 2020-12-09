#include "../header/task.h"
#include "../header/Incomplete.h"

Task::Task()
{
    state = new Incomplete(this);

    taskName = "Untitled";
    description = "No description";
    dueDate = QDate::currentDate();
}

Task::Task(QString name, QString desc, QDate date, CompletionState* state /* = nullptr */)
{
    if(state == nullptr)
    {
        state = new Incomplete(this);
    }

    taskName = name;
    description = desc;
    dueDate = date;
}

Task::~Task()
{
    if(state)
    {
        delete state;
    }

    for(auto t : taskList)
    {
        delete t;
    }
}

bool Task::checkCompletion()
{
    return state->checkCompletion();
}

std::string Task::toDo()
{
    return state->printToDo();
}

void Task::changeState(CompletionState* state) {
    if (this->state != nullptr)
        delete this->state;
    this->state = state;
}
/* MOCK FUNCTIONS NEEDED FOR TESTING STATE METHODS */
void Task::setName(std::string name) {
    this->taskName = QString::fromStdString(name);
}
void Task::setDescription(std::string desc) {
    this->description = QString::fromStdString(desc);
}
void Task::setDate(int y, int m, int d) {
    this->dueDate = QDate(y,m,d);
}

std::string Task::getName() {
    return taskName.toStdString();
}
std::string Task::getDescription() {
    return description.toStdString();
}
std::string Task::getDate() {
        return dueDate.toString("MM-dd-yyyy").toStdString();
}
