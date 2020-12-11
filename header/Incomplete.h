#ifndef __INCOMPLETE_H__
#define __INCOMPLETE_H__

#include "CompletionState.h"

class Incomplete : public CompletionState {
    public:
        Incomplete(Task* task);
        ~Incomplete();
        virtual bool checkCompletion() override;
        virtual std::string printToDo() override;
        virtual std::string toStr() const override;
};

#endif // __INCOMPLETE_H__
