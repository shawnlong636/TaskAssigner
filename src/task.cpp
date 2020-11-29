#include "../header/task.h"

bool Task::checkCompletion()
{
    // TODO: Return value based on completionState
    return true;    // Place holder
}

void Task::toDo()
{
    // TODO: PrintToDo based on completionState
}

void Task::changeState(CompletionState* state) {
    this->state = state;
}