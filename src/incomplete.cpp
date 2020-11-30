#include "../header/incomplete.h"

Incomplete::Incomplete(Task* task) : CompletionState(task) { }
Incomplete::~Incomplete() { }

bool Incomplete::checkCompletion() {
    return false;
}

std::string Incomplete::printToDo() { 
    // TODO: Implement print function
    return "";
}