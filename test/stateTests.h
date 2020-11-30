#include "gtest/gtest.h"

#include "../header/completionState.h"
#include "../header/task.h"
#include "../header/complete.h"

TEST(CompleteTests, checkCompletion) {
    Task* task = new Task();
    CompletionState* state = new Complete(task);

    EXPECT_TRUE(state->checkCompletion());
    delete state;
}

TEST(CompleteTests, printToDo) {
    Task* task = new Task();
    EXPECT_TRUE(true);
}