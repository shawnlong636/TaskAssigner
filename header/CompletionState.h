#ifndef __COMPLETIONSTATE_H__
#define __COMPLETIONSTATE_H__

#include "task.h"

class Task;

class CompletionState {
    protected:
        Task* task;
    public:
        virtual bool checkCompletion() = 0;
        virtual void printToDo() = 0;
};

#endif // __COMPLETIONSTATE_H__