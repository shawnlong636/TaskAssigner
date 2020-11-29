#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QVector>
#include "completionState.h" // Needed for ChangeState

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
};

#endif // TASK_H
