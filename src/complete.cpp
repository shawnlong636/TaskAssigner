#include "../header/Complete.h"

Complete::Complete(Task* task) : CompletionState(task) { }
Complete::~Complete() { }

bool Complete::checkCompletion() {
    return true;
}

std::string Complete::printToDo() { 
    std::string str = "";
    if (task->getName()!="")
        str = task->getName();
    str += "\t";
    if (task->getDescription()!="")
        str += task->getDescription();
    str += "\t";
    if (task->getDate()!="")
        str += task->getDate();
    str += "\tComplete\t\n";

    return str;
}

std::string Complete::toStr() const {
    return "complete";
}
