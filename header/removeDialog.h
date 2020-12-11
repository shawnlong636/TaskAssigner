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
    removeDialog(QWidget *parent = nullptr, Task* rootTask = nullptr, int activeRow = 0);
    ~removeDialog();
    virtual void display() override;

signals:
    void sendRowToRemove(int row);

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::removeDialog *ui;
    int row;
};

#endif // REMOVEDIALOG_H
