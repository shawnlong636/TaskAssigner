#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include "dialog.h"
#include <QDialog>

namespace Ui {
class removeDialog;
}

class removeDialog : public Dialog
{
    Q_OBJECT

public:
    removeDialog(QWidget *parent = nullptr);
    ~removeDialog();
    virtual void display() override;

private:
    Ui::removeDialog *ui;
};

#endif // REMOVEDIALOG_H
