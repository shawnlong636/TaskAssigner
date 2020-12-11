#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include "dialog.h"
#include <QDialog>

namespace Ui {
class editDialog;
}

class editDialog : public Dialog
{
    Q_OBJECT

public:
    editDialog(QWidget *parent = nullptr);
    ~editDialog();
    virtual void display() override;

private:
    Ui::editDialog *ui;
};

#endif // EDITDIALOG_H
