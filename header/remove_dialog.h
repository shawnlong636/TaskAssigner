#ifndef REMOVE_DIALOG_H
#define REMOVE_DIALOG_H

#include <QDialog>

namespace Ui {
class Remove_Dialog;
}

class Remove_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Remove_Dialog(QWidget *parent = nullptr);
    ~Remove_Dialog();

private:
    Ui::Remove_Dialog *ui;
};

#endif // REMOVE_DIALOG_H
