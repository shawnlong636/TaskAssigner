#include "../header/incomplete.h"

Incomplete::Incomplete(Task* task) : CompletionState(task) { }
Incomplete::~Incomplete() { }

bool Incomplete::checkCompletion() {
    return false;
}

std::string Incomplete::printToDo() { 
    std::string str = "";
    if (task->getName()!="")
        str = task->getName();
    str += "\t";
    if (task->getDescription()!="")
        str += task->getDescription();
    str += "\t";
    if (task->getDate()!="")
        str += task->getDate();
    str += "\tIncomplete\t\n";

    return str;
}
