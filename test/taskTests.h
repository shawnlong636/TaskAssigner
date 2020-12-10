#ifndef TASKTESTS_H
#define TASKTESTS_H


#include "gtest/gtest.h"

#include "../header/task.h"

TEST(AddTests, AddOne) {
    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"FirstTask\tNo description\t" + tempDate + "\tIncomplete\t\n");



    delete root;
}

TEST(AddTests, AddThree) {
    qDebug() << "AddTest starts here";

    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    qDebug() << "About to call toDo()";

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"FirstTask\tNo description\t" + tempDate + "\tIncomplete\t\n");

    delete root;
}

#endif // TASKTESTS_H
