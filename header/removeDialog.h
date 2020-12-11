#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include "dialog.h"
#include <QDialog>

class Task;

namespace Ui {
class removeDialog;
}

class removeDialog : public Dialog
{
    Q_OBJECT

public:
    removeDialog(QWidget *parent = nullptr, Task* taskToRemove = nullptr);
    ~removeDialog();
    virtual void display() override;

private:
    Ui::removeDialog *ui;
    Task* focusedTask;
};

#endif // REMOVEDIALOG_H
