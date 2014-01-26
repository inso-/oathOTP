#ifdef WIN32
#include <direct.h>
#include <io.h>
#else
#include <dirent.h>
#endif
#include <QKeyEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addaccount.h"
#include "accountconfigfile.h"
#include "otp.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string     name;

#ifdef WIN32
    struct _finddata_t c_fichier;
    intptr_t hFichier;
    hFichier = _findfirst( "*.conf" ,&c_fichier );

    if (hFichier != -1)
    {
        do if (c_fichier.size!=0)
        {
            name = c_fichier.name;
            name = name.substr(0 ,name.length() - 5 );
            Accountconfigfile *a = new Accountconfigfile(name) ;
            AccountList[name] = a;

        }
        while( _findnext( hFichier, &c_fichier ) == 0 );
    }
#else
    DIR *dpdf;
    struct dirent *epdf;

    dpdf = opendir("./");
    if (dpdf != NULL){
        while ((epdf = readdir(dpdf))){
            name = epdf->d_name;
            if (name.length() > 6 && name.substr(name.length() - 5, name.length()) == ".conf")
                {
                    name = name.substr(0 , name.length() - 5);
                    Accountconfigfile *a = new Accountconfigfile(name) ;
                    AccountList[name] = a;
                }
        }
    closedir(dpdf);
    }

#endif


    refreshAccountList();
}

void MainWindow::refreshAccountList()
{
    ui->Accounts->clear();
    std::map<std::string,Accountconfigfile*>::iterator End = AccountList.end();

    for (std::map<std::string,Accountconfigfile*>::iterator it = AccountList.begin(); it != End; ++it)
        ui->Accounts->addItem(it->second->getName().c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionManage_account_triggered()
{
    AddAccount  a(this);

    a.exec();
    refreshAccountList();
}

void MainWindow::on_getToken_clicked()
{
//    getName();
//        std::string getSecretkey();
//        int         getnbDigit();
//        int         getTime();


    std::string account = ui->Accounts->currentText().toStdString();

    if (account.empty())
        return;
    else
       {
           OTP     generator(AccountList[account]->getSecretkey(), AccountList[account]->getTime());
           ui->Token->setText(generator.generate().c_str());
    }
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        if (ke->key() == Qt::Key::Key_Enter ||
            ke->key() == Qt::Key::Key_Return)
            emit on_getToken_clicked();
    }
    return QWidget::event(event);
}
