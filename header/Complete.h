#ifndef __COMPLETE_H__
#define __COMPLETE_H__

#include "completionState.h"

class Complete : public CompletionState {
    public:
        Complete();
        virtual bool checkCompletion() override;
        virtual void printToDo() override;
};

#endif // __COMPLETE_H__