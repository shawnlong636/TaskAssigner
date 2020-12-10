#ifndef STATETESTS_H
#define STATETESTS_H

#include "gtest/gtest.h"

#include "../header/CompletionState.h"
#include "../header/task.h"
#include "../header/Complete.h"
#include "../header/Incomplete.h"
#include "../header/InProgress.h"

TEST(CompleteTests, checkCompletion) {
    Task* task = new Task();
    CompletionState* state = new Complete(task);

    EXPECT_TRUE(state->checkCompletion());

    delete task;
}

TEST(CompleteTests, printToDo) { 
    Task* task = new Task();
    std::string name = "Expense Report";
    std::string desc = "Finish October Expense Report and send to Jack";
    std::string date = "11-15-2020";
    
    CompletionState* state = new Complete(task);

    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(state->printToDo(),"Untitled\tNo description\t" + tempDate + "\tComplete\t\n");

    task->setName(name);

    EXPECT_EQ(state->printToDo(),"Expense Report\tNo description\t" + tempDate + "\tComplete\t\n");
    
    task->setDescription(desc);
    
    EXPECT_EQ(state->printToDo(),"Expense Report\tFinish October Expense Report and send to Jack\t" + tempDate + "\tComplete\t\n");

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

TEST(IncompleteTests, printToDo) { 
    Task* task = new Task();
    std::string name = "Finish Coding Project";
    std::string desc = "Put the final touches on the coding project for CS 100";
    std::string date = "12-11-2020";
    
    CompletionState* state = new Incomplete(task);

    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(state->printToDo(),"Untitled\tNo description\t" + tempDate + "\tIncomplete\t\n");

    task->setName(name);

    EXPECT_EQ(state->printToDo(),"Finish Coding Project\tNo description\t" + tempDate + "\tIncomplete\t\n");
    
    task->setDescription(desc);
    
    EXPECT_EQ(state->printToDo(),"Finish Coding Project\tPut the final touches on the coding project for CS 100\t" + tempDate + "\tIncomplete\t\n");

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

TEST(InProgressTests, printToDo) {
    Task* task = new Task();
    std::string name = "Unit tests for state pattern";
    std::string desc = "Complete the unit tests for the state pattern";
    std::string date = "11-30-2020";
    
    CompletionState* state = new InProgress(task);

    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(state->printToDo(),"Untitled\tNo description\t" + tempDate + "\tInProgress\t\n");

    task->setName(name);

    EXPECT_EQ(state->printToDo(),"Unit tests for state pattern\tNo description\t" + tempDate + "\tInProgress\t\n");
    
    task->setDescription(desc);
    
    EXPECT_EQ(state->printToDo(),"Unit tests for state pattern\tComplete the unit tests for the state pattern\t" + tempDate + "\tInProgress\t\n");

    task->setDate(2020,11,30);

    EXPECT_EQ(state->printToDo(),"Unit tests for state pattern\tComplete the unit tests for the state pattern\t11-30-2020\tInProgress\t\n");

    delete task;
}

TEST(DynamicTests, IntegratedTest) {
    Task* task = new Task();
    task->changeState(new Incomplete(task));

    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_FALSE(task->checkCompletion());

    task->setName("Perform a integrated test");

    EXPECT_EQ(task->toDo(), "Perform a integrated test\tNo description\t" + tempDate + "\tIncomplete\t\n");
    
    task->setName("Perform an integrated test");
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNo description\t" + tempDate + "\tIncomplete\t\n");

    task->changeState(new InProgress(task));
    
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNo description\t" + tempDate + "\tInProgress\t\n");

    task->setDescription("Try really hard to write tests that'll break the code");
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tTry really hard to write tests that'll break the code\t" + tempDate + "\tInProgress\t\n");

    task->setDescription("Not too bad! Keep working at it.");
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNot too bad! Keep working at it.\t" + tempDate + "\tInProgress\t\n");

    task->setDate(2020,12,1);
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNot too bad! Keep working at it.\t12-01-2020\tInProgress\t\n");

    task->changeState(new Complete(task));
    EXPECT_EQ(task->toDo(), "Perform an integrated test\tNot too bad! Keep working at it.\t12-01-2020\tComplete\t\n");

    delete task;
}

#endif // STATETESTS_H
