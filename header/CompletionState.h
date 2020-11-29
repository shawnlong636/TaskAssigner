#ifndef __COMPLETIONSTATE_H__
#define __COMPLETIONSTATE_H__

class CompletionState {
    public:
        virtual bool checkCompletion() = 0;
        virtual void printToDo() = 0;
}

#endif // __COMPLETIONSTATE_H__