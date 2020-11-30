#include "gtest/gtest.h"

#include "../header/completionState.h"
#include "../header/task.h"
#include "../header/complete.h"

TEST(CompleteTests,test1) {
    CompletionState* state = new Complete();
    EXPECT_TRUE(state->checkCompletion());
}