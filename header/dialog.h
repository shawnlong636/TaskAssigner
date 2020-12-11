#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr) : QDialog(parent) { }
    ~Dialog() { }
    virtual void display() = 0;

};

#endif // DIALOG_H
