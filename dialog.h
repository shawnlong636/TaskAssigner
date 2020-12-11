#ifndef DIALOG_H
#define DIALOG_H
#include "../header/task.h"
#include <QTableWidget>
#include <QDateEdit>
class Dialog
{
private:

public:
     Dialog();
    ~Dialog();
    virtual void implementAction() = 0;

};

#endif // DIALOG_H
