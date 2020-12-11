#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "dialog.h"

namespace Ui {
class addDialog;
}

class addDialog : public Dialog
{
    Q_OBJECT

public:
    addDialog(QWidget *parent = nullptr);
    ~addDialog();
    virtual void display() override;

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
