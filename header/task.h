#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QVector>

class Task
{
private:
    QString taskName;
    QString description;
    QDate* dueDate;
    // TODO: CompletionState goes here (not implemented yet)
    QVector<Task*> taskList;

public:
    bool checkCompletion();
    void toDo();
    void changeState(/* TODO: CompletionState as parameter when implemented */);
};

#endif // TASK_H
