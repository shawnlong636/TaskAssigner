#include "../header/incomplete.h"

Incomplete::Incomplete(Task* task) : CompletionState(task) { }
Incomplete::~Incomplete() { }

bool Incomplete::checkCompletion() {
    return false;
}

std::string Incomplete::printToDo() { 
    std::string str = task->getName() + "\t";
    str += (task->getDescription() + "\t");
    str += (task->getDate() + "\t");
    str += "Incomplete\t";
    str += "\n";

    return str;
}
