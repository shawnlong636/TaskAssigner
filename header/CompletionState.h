#ifndef __COMPLETIONSTATE_HPP__
#define __COMPLETIONSTATE_HPP__

class CompletionState {
    public:
        virtual bool checkCompletion() = 0;
        virtual void printToDo() = 0;
}

#endif // __COMPLETIONSTATE_HPP__