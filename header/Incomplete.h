#ifndef __INCOMPLETE_H__
#define __INCOMPLETE_H__

#include "completionState.h"

class Incomplete : CompletionState {
    virtual bool checkCompletion() override;
    virtual void printToDo() override;
};

#endif // __INCOMPLETE_H__