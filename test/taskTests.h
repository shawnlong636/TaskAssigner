#ifndef TASKTESTS_H
#define TASKTESTS_H


#include "gtest/gtest.h"

#include "../header/task.h"

TEST(AddTests, AddOne) {
    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"FirstTask\tNo description\t" + tempDate + "\tIncomplete\t\n");

    root->getSubtaskAt(0)->setDescription("This is the first task");

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"FirstTask\tThis is the first task\t" + tempDate + "\tIncomplete\t\n");

    root->getSubtaskAt(0)->setDate(2021, 1, 1);

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"FirstTask\tThis is the first task\t01-01-2021\tIncomplete\t\n");

    delete root;
}

TEST(AddTests, AddThree) {

    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    root->addSubtask(new Task("SecondTask"));
    root->addSubtask(new Task("ThirdTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"FirstTask\tNo description\t" + tempDate + "\tIncomplete\t\n");
    EXPECT_EQ(root->getSubtaskAt(1)->toDo(),"SecondTask\tNo description\t" + tempDate + "\tIncomplete\t\n");
    EXPECT_EQ(root->getSubtaskAt(2)->toDo(),"ThirdTask\tNo description\t" + tempDate + "\tIncomplete\t\n");

    delete root;
}

TEST(AddTests, GetInvalid) {

    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    root->addSubtask(new Task("SecondTask"));
    root->addSubtask(new Task("ThirdTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(root->getSubtaskAt(2)->toDo(),"ThirdTask\tNo description\t" + tempDate + "\tIncomplete\t\n");
    EXPECT_EQ(root->getSubtaskAt(3), nullptr);

    delete root;
}

TEST(AddTests, ConstructorTest) {

    Task* root = new Task("Root", "Root description", QDate(2021, 11, 11));

    EXPECT_EQ(root->toDo(),"Root\tRoot description\t11-11-2021\tIncomplete\t\n");

    delete root;
}

TEST(AddTests, RemoveTest) {

    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    root->addSubtask(new Task("SecondTask"));
    root->addSubtask(new Task("ThirdTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(root->getSubtaskAt(2)->toDo(),"ThirdTask\tNo description\t" + tempDate + "\tIncomplete\t\n");

    root->removeSubtaskAt(2);

    EXPECT_EQ(root->getSubtaskAt(2), nullptr);

    EXPECT_EQ(root->getSubtaskAt(1)->toDo(),"SecondTask\tNo description\t" + tempDate + "\tIncomplete\t\n");

    root->removeSubtaskAt(1);

    EXPECT_EQ(root->getSubtaskAt(1), nullptr);

    delete root;
}

#endif // TASKTESTS_H
