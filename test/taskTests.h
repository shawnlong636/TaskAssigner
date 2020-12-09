#ifndef TASKTESTS_H
#define TASKTESTS_H


#include "gtest/gtest.h"

#include "../header/task.h"
#include <QtDebug>

TEST(AddTests, AddOne) {
    qDebug() << "AddTest starts here";

    Task* root = new Task("Root");
    root->addSubtask(new Task("FirstTask"));
    root->addSubtask(new Task("SecondTask"));
    std::string tempDate = QDate::currentDate().toString("MM-dd-yyyy").toStdString();

    qDebug() << "About to call toDo()";

    EXPECT_EQ(root->getSubtaskAt(0)->toDo(),"Untitled\tNo description\t" + tempDate + "\tIncomplete\t\n");

    delete root;
}

#endif // TASKTESTS_H
