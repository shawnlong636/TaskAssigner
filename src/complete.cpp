#include "../header/complete.h"

Complete::Complete(Task* task) : CompletionState(task) { }
Complete::~Complete() { }

bool Complete::checkCompletion() {
    return true;
}

std::string Complete::printToDo() { 
    std::string str = task->getName() + "\t";
    str += (task->getDescription() + "\t");
    str += (task->getDate() + "\t");
    str += "Complete\t";
    str += "\n";

    return str;
}