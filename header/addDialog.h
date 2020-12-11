#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "dialog.h"
#include <QString>
#include <Qdate>

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

signals:
    void sendTaskData(const QString& taskName, const QString& description, const QDate& dueDate);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addDialog *ui;
    QString taskName;
    QString description;
    QDate dueDate;
};

#endif // ADDDIALOG_H
