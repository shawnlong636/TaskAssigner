#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QVector>
#include "completionState.h" // Needed for ChangeState
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 97ea701430929db999d7359fc35e47172c4f2b84

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
<<<<<<< HEAD
    void setName(std::string name); // Mock Function needed to test State functionality
    void setDescription(std::string desc); // Mock Function needed to test State functionality
    void setDate(std::string date); // Mock Function needed to test State functionality
=======
>>>>>>> 97ea701430929db999d7359fc35e47172c4f2b84
};

#endif // TASK_H
