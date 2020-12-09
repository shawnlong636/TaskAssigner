#include "gtest/gtest.h"

#include "../header/completionState.h"
#include "../header/task.h"
#include "../header/complete.h"
#include "../header/incomplete.h"
#include "../header/inProgress.h"

TEST(CompleteTests, checkCompletion) {
    Task* task = new Task();
    CompletionState* state = new Complete(task);

    EXPECT_TRUE(state->checkCompletion());

    delete task;
}

TEST(CompleteTests, printToDo) { // FIXME: Create Test once decided on impl. of printToDo
    Task* task = new Task();
    std::string name = "Expense Report";
    std::string desc = "Finish October Expense Report and send to Jack";
    std::string date = "11-15-2020";
    
    CompletionState* state = new Complete(task);

    EXPECT_EQ(state->printToDo(),"\t\t\tComplete\t\n");

    task->setName(name);

    EXPECT_EQ(state->printToDo(),"Expense Report\t\t\tComplete\t\n");
    
    task->setDescription(desc);
    
    EXPECT_EQ(state->printToDo(),"Expense Report\tFinish October Expense Report and send to Jack\t\tComplete\t\n");

    task->setDate(2020,11,15);

    EXPECT_EQ(state->printToDo(),"Expense Report\tFinish October Expense Report and send to Jack\t11-15-2020\tComplete\t\n");

    delete task;
}

TEST(IncompleteTests, checkCompletion) {
    Task* task = new Task();
    CompletionState* state = new Incomplete(task);

    EXPECT_FALSE(state->checkCompletion());

    delete task;
}

TEST(IncompleteTests, printToDo) { // FIXME: Create Test once decided on impl. of printToDo
    Task* task = new Task();
    std::string name = "Finish Coding Project";
    std::string desc = "Put the final touches on the coding project for CS 100";
    std::string date = "12-11-2020";
    
    CompletionState* state = new Incomplete(task);

    EXPECT_EQ(state->printToDo(),"\t\t\tIncomplete\t\n");

    task->setName(name);

    EXPECT_EQ(state->printToDo(),"Finish Coding Project\t\t\tIncomplete\t\n");
    
    task->setDescription(desc);
    
    EXPECT_EQ(state->printToDo(),"Finish Coding Project\tPut the final touches on the coding project for CS 100\t\tIncomplete\t\n");

    task->setDate(2020,12,11);

    EXPECT_EQ(state->printToDo(),"Finish Coding Project\tPut the final touches on the coding project for CS 100\t12-11-2020\tIncomplete\t\n");

    delete task;
}

TEST(InProgressTests, checkCompletion) {
    Task* task = new Task();
    CompletionState* state = new InProgress(task);

    EXPECT_FALSE(state->checkCompletion());

    delete task;
}

TEST(InProgressTests, printToDo) { // FIXME: Create Test once decided on impl. of printToDo
    Task* task = new Task();
    std::string name = "Unit tests for state pattern";
    std::string desc = "Complete the unit tests for the state pattern";
    std::string date = "11-30-2020";
    
    CompletionState* state = new InProgress(task);

    EXPECT_EQ(state->printToDo(),"\t\t\tInProgress\t\n");

    task->setName(name);

    EXPECT_EQ(state->printToDo(),"Unit tests for state pattern\t\t\tInProgress\t\n");
    
    task->setDescription(desc);
    
    EXPECT_EQ(state->printToDo(),"Unit tests for state pattern\tComplete the unit tests for the state pattern\t\tInProgress\t\n");

    task->setDate(2020,11,30);

    EXPECT_EQ(state->printToDo(),"Unit tests for state pattern\tComplete the unit tests for the state pattern\t11-30-2020\tInProgress\t\n");

    delete task;
}

TEST(DynamicTests, IntegratedTest) {
    Task* task = new Task();
    task->changeState(new Incomplete(task));

    EXPECT_FALSE(task->checkCompletion());

    task->setName("Perform a integrated test");

    EXPECT_EQ(task->toDo(), "Perform a integrated test\t\t\tIncomplete\t\n");
    
    task->setName("Perform an integrated test");
    EXPECT_EQ(task->toDo(), "Perform an integrated test\t\t\tIncomplete\t\n");

    task->changeState(new InProgress(task));
    
    EXPECT_EQ(task->toDo(), "Perform an integrated test\t\t\tInProgress\t\n");

    task->setDescription("Try really hard to write tests that'll break the code");
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tTry really hard to write tests that'll break the code\t\tInProgress\t\n");

    task->setDescription("Not too bad! Keep working at it.");
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNot too bad! Keep working at it.\t\tInProgress\t\n");

    task->setDate(2020,12,1);
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNot too bad! Keep working at it.\t12-01-2020\tInProgress\t\n");

    task->changeState(new Complete(task));
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNot too bad! Keep working at it.\t12-01-2020\tComplete\t\n");

    delete task;
}
