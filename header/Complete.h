#ifndef __COMPLETE_H__
#define __COMPLETE_H__

#include "completionState.h"

class Complete : CompletionState {
    virtual bool checkCompletion() override;
    virtual void printToDo() override;
};

#endif // __COMPLETE_H__