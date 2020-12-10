#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Forward declaration
class Task;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_editButton_clicked();

    void on_removeButton_clicked();

    void on_showButton_clicked();

private:
    Ui::MainWindow *ui;

    int activeRow;

    // All tasks should be children of this task
    Task* rootTask;
};
#endif // MAINWINDOW_H
