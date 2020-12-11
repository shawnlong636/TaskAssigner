#ifndef EDIT_DIALOG_H
#define EDIT_DIALOG_H

#include <QDialog>
#include "../header/dialog.h"
#include "../header/task.h"
#include <QTableWidget>
namespace Ui {
class Edit_Dialog;
}

class Edit_Dialog : public QDialog, public Dialog
{
    Q_OBJECT

public:
    QString Name;
    QString Description;
    QString Date;

    explicit Edit_Dialog(QWidget *parent = nullptr);
    void implementAction();
    ~Edit_Dialog();

private:
    Ui::Edit_Dialog *ui;
    Task* input;
};

#endif // EDIT_DIALOG_H
