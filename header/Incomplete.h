#ifndef __INCOMPLETE_H__
#define __INCOMPLETE_H__

#include "completionState.h"

class Incomplete : public CompletionState {
    public:
        Incomplete(Task* task);
        ~Incomplete();
        virtual bool checkCompletion() override;
        virtual std::string printToDo() override;
};

#endif // __INCOMPLETE_H__