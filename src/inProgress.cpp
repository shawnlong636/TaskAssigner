#include "../header/inProgress.h"

InProgress::InProgress(Task* task) : CompletionState(task) { }
InProgress::~InProgress() { }

bool InProgress::checkCompletion() {
    return true;
}

std::string InProgress::printToDo() { 
    std::string str = task->getName() + "\t";
    str += (task->getDescription() + "\t");
    str += (task->getDate() + "\t");
    str += "InProgress\t";
    str += "\n";

    return str;
}