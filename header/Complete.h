#ifndef __COMPLETE_H__
#define __COMPLETE_H__

#include "CompletionState.h"

class Complete : public CompletionState {
    public:
        Complete(Task* task);
        ~Complete();
        virtual bool checkCompletion() override;
        virtual std::string printToDo() override;
        virtual std::string toStr() const override;
};

#endif // __COMPLETE_H__
