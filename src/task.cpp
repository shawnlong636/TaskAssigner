#include "../header/task.h"
#include "../header/Incomplete.h"
#include <QtDebug>

Task::Task()
{
    state = new Incomplete(this);

    taskName = "Untitled";
    description = "No description";
    dueDate = QDate::currentDate();
}

Task::Task(QString name, QString desc /* = "No description"*/, QDate date /* = QDate::currentDate()*/)
{
    this->state = new Incomplete(this);

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
    std::string str = state->printToDo();

    for (int i = 0; i<this->taskList.size();i++) {
        if (taskList.at(i)) {
            str += this->getName() + "\t";
            str += taskList.at(i)->toDo();
        }
    }
    return str;
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

Task* Task::getSubtaskAt(int index)
{
    if(index >= taskList.length() || index < 0)
    {
        return nullptr;
    }

    return taskList[index];
}

void Task::addSubtask(Task* taskToAdd, int index /* = -1 */)
{
    if(index < -1)
    {
        qDebug() << "Can't add task at index " << index;
        return;
    }

    if(index == -1)
    {
        // If no index specified, add at end
        taskList.append(taskToAdd);
    }
    else
    {
        // Otherwise insert at appropriate location
        taskList.insert(index, taskToAdd);
    }

    qDebug() << "Current size of taskList = " << taskList.length();
}

void Task::removeSubtaskAt(int index)
{
    if(index >= taskList.length() || index < 0)
    {
        qDebug() << "No task to remove at index " << index;
        return;
    }

    delete taskList[index];

    taskList.remove(index);

    qDebug() << "Current size of taskList = " << taskList.length();
}

int Task::getNumOfSubtasks()
{
    return taskList.length();
}
