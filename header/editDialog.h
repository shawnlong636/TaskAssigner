#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include "dialog.h"
#include "InProgress.h"
#include "Incomplete.h"
#include "Complete.h"
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
public slots:
    void receiveCurrentTask(const QString& name, const QString& desc, const QDate& date, const CompletionState& state);

signals:
    void sendTaskData(const QString& taskName, const QString& description, const QDate& dueDate, const QString& state);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::editDialog *ui;
    QString taskName;
    QString description;
    QDate dueDate;
    QString state;
};

#endif // EDITDIALOG_H
