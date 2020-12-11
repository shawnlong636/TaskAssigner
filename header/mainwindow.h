#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addDialog.h"
#include "removeDialog.h"
#include "editDialog.h"
#include "InProgress.h"
#include "Incomplete.h"
#include "Complete.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

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
    void setIsRoot(bool isRoot);
    void setRootTask(Task* task);

private slots:
    void on_addButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_editButton_clicked();

    void on_removeButton_clicked();

    void on_showButton_clicked();

    void on_actionAboutQt_triggered();

    void on_actionExport_triggered();

    void on_actionAbout_triggered();
public slots:
    void receiveNewTask(const QString& taskName, const QString& description, const QDate& dueDate);
    void receiveExistingTask(const QString& taskName, const QString& description, const QDate& dueDate, const QString& state);
    void receiveRemoveTask(int row);
signals:
    void pushCurrentSettings(const QString& name, const QString& desc, const QDate& date, const CompletionState& state);

private:
    Ui::MainWindow *ui;

    int activeRow;
    bool isRoot;

    // All tasks should be children of this task
    Task* rootTask;
    addDialog* add;
    editDialog* edit;
    removeDialog* rmv;
};
#endif // MAINWINDOW_H
