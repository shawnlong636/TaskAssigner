#include "../header/InProgress.h"

InProgress::InProgress(Task* task) : CompletionState(task) { }
InProgress::~InProgress() { }

bool InProgress::checkCompletion() {
    return false;
}

std::string InProgress::printToDo() { 
    std::string str = "";
    if (task->getName()!="")
        str = task->getName();
    str += "\t";
    if (task->getDescription()!="")
        str += task->getDescription();
    str += "\t";
    if (task->getDate()!="")
        str += task->getDate();
    str += "\tInProgress\t\n";

    return str;
}

std::string InProgress::toStr() const {
    return "inprogress";
}
