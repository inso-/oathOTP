#ifndef ADDACCOUNT_H
#define ADDACCOUNT_H

#include <QDialog>
#include <string>

namespace Ui {
class AddAccount;
}

class AddAccount : public QDialog
{
    Q_OBJECT

public:
    explicit AddAccount(QWidget *parent = 0);
    ~AddAccount();


private slots:
    void on_AddModify_clicked();

    void on_AccountList_activated(const QString &arg1);

    void on_Delete_clicked();

    void on_AccountList_currentIndexChanged(const QString &arg1);

private:
    Ui::AddAccount *ui;
    std::string     _selected;
};

#endif // ADDACCOUNT_H
