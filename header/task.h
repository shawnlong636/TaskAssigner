#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QVector>
#include "CompletionState.h" // Needed for ChangeState
#include <string>
#include <iostream>

class CompletionState; // Added to avoid circular dependency

class Task
{
private:
    QString taskName;
    QString description;
    QDate dueDate;
    CompletionState* state;// Added newly implemented CompletionState
    QVector<Task*> taskList;

public:
    Task();
    Task(QString name, QString desc = "No description", QDate date = QDate::currentDate());
    ~Task();

    bool checkCompletion();
    std::string toDo();
    void changeState(CompletionState* state);
    void setName(std::string name); // Mock Function needed to test State functionality
    void setDescription(std::string desc); // Mock Function needed to test State functionality
    void setDate(int y, int m, int d); // Mock Function needed to test State functionality
    void setQDate(QDate date);
    std::string getName();
    std::string getDescription();
    std::string getDate();
    QDate getQDate();
    CompletionState* getState();

    Task* getSubtaskAt(int index);
    void addSubtask(Task* taskToAdd, int index = -1);
    void removeSubtaskAt(int index);
    int getNumOfSubtasks();
};

#endif // TASK_H
