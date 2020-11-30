#ifndef __INPROGRESS_H__
#define __INPROGRESS_H__

#include "completionState.h"

class InProgress : public CompletionState {
    public:
        InProgress();
        ~InProgress();
        virtual bool checkCompletion() override;
        virtual void printToDo() override;
};

#endif // __INPROGRESS_H__