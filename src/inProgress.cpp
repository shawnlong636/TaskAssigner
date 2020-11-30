#include "../header/inProgress.h"

InProgress::InProgress(Task* task) : CompletionState(task) { }
InProgress::~InProgress() { }

bool InProgress::checkCompletion() {
    return true;
}

std::string InProgress::printToDo() { 
    // TODO: Implement print function
    return "";
}