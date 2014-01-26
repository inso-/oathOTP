/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionManage_account;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *Accounts;
    QLabel *Token;
    QPushButton *getToken;
    QMenuBar *menuBar;
    QMenu *menuConfiguration;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(274, 163);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressource/ressource/oathOTP-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionManage_account = new QAction(MainWindow);
        actionManage_account->setObjectName(QStringLiteral("actionManage_account"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label);

        Accounts = new QComboBox(centralWidget);
        Accounts->setObjectName(QStringLiteral("Accounts"));

        horizontalLayout->addWidget(Accounts);


        verticalLayout->addLayout(horizontalLayout);

        Token = new QLabel(centralWidget);
        Token->setObjectName(QStringLiteral("Token"));

        verticalLayout->addWidget(Token);


        verticalLayout_2->addLayout(verticalLayout);

        getToken = new QPushButton(centralWidget);
        getToken->setObjectName(QStringLiteral("getToken"));

        verticalLayout_2->addWidget(getToken);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 274, 22));
        menuConfiguration = new QMenu(menuBar);
        menuConfiguration->setObjectName(QStringLiteral("menuConfiguration"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuConfiguration->menuAction());
        menuConfiguration->addAction(actionManage_account);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OTP Generator", 0));
        actionManage_account->setText(QApplication::translate("MainWindow", "Add account", 0));
        label->setText(QApplication::translate("MainWindow", "Account        ", 0));
        Token->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        getToken->setText(QApplication::translate("MainWindow", "Get Token", 0));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
