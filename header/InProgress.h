#ifndef __INPROGRESS_H__
#define __INPROGRESS_H__

#include "CompletionState.h"

class InProgress : public CompletionState {
    public:
        InProgress(Task* task);
        ~InProgress();
        virtual bool checkCompletion() override;
        virtual std::string printToDo() override;
        virtual std::string toStr() const override;
};

#endif // __INPROGRESS_H__
