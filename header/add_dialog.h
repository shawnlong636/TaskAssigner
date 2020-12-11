#ifndef ADD_DIALOG_H
#define ADD_DIALOG_H

#include <QDialog>
#include "../header/dialog.h"
#include "../header/task.h"
#include <QTableWidget>
class Task;
namespace Ui {
class Add_Dialog;
}

class Add_Dialog : public QDialog, public Dialog
{
    Q_OBJECT

public:
    QString Name;
    QString Description;
    QString Date;

     explicit Add_Dialog(QWidget *parent = nullptr);
     void implementAction();
     void set_task(Task*  t);
     Task* get_task();
      ~Add_Dialog();
signals:
     void transferData(QString Name, QString Description, QString Date);
private slots:



private:

    Ui::Add_Dialog *ui;
    Task* input;
};

#endif // ADD_DIALOG_H
