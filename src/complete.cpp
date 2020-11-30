#include "../header/complete.h"

Complete::Complete(Task* task) : CompletionState(task) { }
Complete::~Complete() { }

bool Complete::checkCompletion() {
    return true;
}

std::string Complete::printToDo() { 
    // TODO: Implement print function
    return "";
}