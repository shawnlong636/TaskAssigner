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

TEST(CompleteTests, printToDo) { // FIXME: Create Test once decided on impl. of printToDo
    Task* task = new Task();
    task->setName("Clean Up");
    task->setDescription("Kitchen, living room, bedrooms");
    task->setDate("12-31-2020");

    EXPECT_TRUE(false);
}