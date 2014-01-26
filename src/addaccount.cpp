#include "addaccount.h"
#include "mainwindow.h"
#include "ui_addaccount.h"
#ifdef WIN32
#include <direct.h>
#include <io.h>
#endif
#include <QDebug>

AddAccount::AddAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAccount)
{
    ui->setupUi(this);
    ui->AccountList->autoCompletion();

    MainWindow  *rparent = dynamic_cast <MainWindow*> (this->parent());

    std::map<std::string,Accountconfigfile*>::iterator End = rparent->AccountList.end();

    for (std::map<std::string,Accountconfigfile*>::iterator it = rparent->AccountList.begin(); it != End; ++it)
    {
        ui->AccountList->addItem(it->second->getName().c_str());
    }
}

AddAccount::~AddAccount()
{
    delete ui;
}

void AddAccount::on_AddModify_clicked()
{
    QString     account;

    MainWindow  *parent = dynamic_cast <MainWindow*> (this->parent());

    account = ui->AccountList->currentText();
    if (ui->SecretKey->text().toStdString().empty())
        return ui->ErrorMessage->setText("Set SecretKey for this Account !");
    if (!parent->AccountList[account.toStdString()])
    {
        ui->AccountList->addItem(account);
        Accountconfigfile *newFile = new Accountconfigfile(account.toStdString());
        parent->AccountList[account.toStdString()] = newFile;
        newFile->setAccountConfig(account.toStdString(),ui->SecretKey->text().toStdString(), ui->Nbdigit->value(), ui->Time->value());
        ui->ErrorMessage->setText("Account Successfull add");
    }
    else
    {
        delete parent->AccountList[account.toStdString()];
        Accountconfigfile *newFile = new Accountconfigfile(account.toStdString());
        parent->AccountList[account.toStdString()] = newFile;
        newFile->setAccountConfig(account.toStdString(),ui->SecretKey->text().toStdString(), ui->Nbdigit->value(), ui->Time->value());
        ui->ErrorMessage->setText("Account Successfull modify");
    }

    ui->AccountList->setCurrentText("");
    ui->SecretKey->setText("");
}

void AddAccount::on_AccountList_activated(const QString &)
{

}

void AddAccount::on_Delete_clicked()
{
    QString     account;
    int         item;
    MainWindow  *parent = dynamic_cast <MainWindow*> (this->parent());
    std::string filename;

    account = ui->AccountList->currentText();
    if (account.isEmpty())
        return;
    item = ui->AccountList->findText(account);
    if (item)
        {
            parent->AccountList.erase(parent->AccountList.find(account.toStdString()));
            filename = account.toStdString() + ".conf";
            remove(filename.c_str());
            ui->AccountList->removeItem(item);
            ui->ErrorMessage->setText("Account Successfull delete");
        }
    ui->AccountList->setCurrentText("");
    ui->SecretKey->setText("");
}

void AddAccount::on_AccountList_currentIndexChanged(const QString &account)
{
   MainWindow  *parent = dynamic_cast <MainWindow*> (this->parent());
   if (!parent->AccountList[account.toStdString()])
       return;
   std::string keypass = parent->AccountList[account.toStdString()]->getSecretkey();
   int         time = parent->AccountList[account.toStdString()]->getTime();
   int         nbDigit = parent->AccountList[account.toStdString()]->getnbDigit();

   if (!keypass.empty())
       ui->SecretKey->setText(keypass.c_str());
   if (time > 0 && time < 500)
       ui->Time->setValue(time);
   if (nbDigit >= 1 && nbDigit < 16)
       ui->Nbdigit->setValue(nbDigit);
}
