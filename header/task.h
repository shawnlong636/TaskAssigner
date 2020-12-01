#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QVector>
#include "completionState.h" // Needed for ChangeState
#include <string>

class CompletionState; // Added to avoid circular dependency

class Task
{
private:
    QString taskName;
    QString description;
    QDate* dueDate;
    CompletionState* state;// Added newly implemented CompletionState
    QVector<Task*> taskList;

public:
    bool checkCompletion();
    void toDo();
    void changeState(CompletionState* state);
    void setName(std::string name); // Mock Function needed to test State functionality
    void setDescription(std::string desc); // Mock Function needed to test State functionality
    void setDate(std::string date); // Mock Function needed to test State functionality
    std::string getName();
    std::string getDescription();
    std::string getDate();
};

#endif // TASK_H
