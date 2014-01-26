#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include "accountconfigfile.h"
#include "Account.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionManage_account_triggered();

    void on_getToken_clicked();

private:
    Ui::MainWindow *ui;

    void refreshAccountList();
    bool event(QEvent *event);

public:
    std::map<std::string, Accountconfigfile*> AccountList;
};

#endif // MAINWINDOW_H
