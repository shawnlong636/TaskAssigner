#ifndef __COMPLETIONSTATE_H__
#define __COMPLETIONSTATE_H__

#include "task.h"
#include <string>


class Task;

class CompletionState {
    protected:
        Task* task;
    public:
        CompletionState(Task* task) : task(task) {}
        virtual ~CompletionState() { }
        virtual bool checkCompletion() = 0;
        virtual std::string printToDo() = 0;
};

#endif // __COMPLETIONSTATE_H__