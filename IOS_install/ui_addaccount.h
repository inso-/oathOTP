/********************************************************************************
** Form generated from reading UI file 'addaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDACCOUNT_H
#define UI_ADDACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddAccount
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *AccountList;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *Nbdigit;
    QLabel *label_4;
    QSpinBox *Time;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *SecretKey;
    QVBoxLayout *verticalLayout;
    QLabel *ErrorMessage;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddModify;
    QPushButton *Delete;
    QPushButton *pushButton;

    void setupUi(QDialog *AddAccount)
    {
        if (AddAccount->objectName().isEmpty())
            AddAccount->setObjectName(QStringLiteral("AddAccount"));
        AddAccount->resize(444, 314);
        horizontalLayout_6 = new QHBoxLayout(AddAccount);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(AddAccount);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_2);

        AccountList = new QComboBox(AddAccount);
        AccountList->setObjectName(QStringLiteral("AccountList"));
        AccountList->setEditable(true);

        horizontalLayout_5->addWidget(AccountList);


        horizontalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(AddAccount);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Nbdigit = new QSpinBox(AddAccount);
        Nbdigit->setObjectName(QStringLiteral("Nbdigit"));
        Nbdigit->setMinimum(1);
        Nbdigit->setMaximum(16);
        Nbdigit->setSingleStep(1);
        Nbdigit->setValue(6);

        horizontalLayout_2->addWidget(Nbdigit);

        label_4 = new QLabel(AddAccount);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        Time = new QSpinBox(AddAccount);
        Time->setObjectName(QStringLiteral("Time"));
        Time->setMinimum(5);
        Time->setMaximum(1024);
        Time->setValue(30);

        horizontalLayout_2->addWidget(Time);

        label_5 = new QLabel(AddAccount);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(AddAccount);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        SecretKey = new QLineEdit(AddAccount);
        SecretKey->setObjectName(QStringLiteral("SecretKey"));
        SecretKey->setInputMethodHints(Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        SecretKey->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_4->addWidget(SecretKey);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ErrorMessage = new QLabel(AddAccount);
        ErrorMessage->setObjectName(QStringLiteral("ErrorMessage"));

        verticalLayout->addWidget(ErrorMessage);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        AddModify = new QPushButton(AddAccount);
        AddModify->setObjectName(QStringLiteral("AddModify"));

        horizontalLayout->addWidget(AddModify);

        Delete = new QPushButton(AddAccount);
        Delete->setObjectName(QStringLiteral("Delete"));

        horizontalLayout->addWidget(Delete);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(AddAccount);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_3);


        retranslateUi(AddAccount);
        QObject::connect(pushButton, SIGNAL(clicked()), AddAccount, SLOT(accept()));

        QMetaObject::connectSlotsByName(AddAccount);
    } // setupUi

    void retranslateUi(QDialog *AddAccount)
    {
        AddAccount->setWindowTitle(QApplication::translate("AddAccount", "Dialog", 0));
        label_2->setText(QApplication::translate("AddAccount", "     Account", 0));
        label->setText(QApplication::translate("AddAccount", "Number of Digit", 0));
        label_4->setText(QApplication::translate("AddAccount", "Counter", 0));
        label_5->setText(QApplication::translate("AddAccount", "second", 0));
        label_6->setText(QApplication::translate("AddAccount", "SecretKey", 0));
        ErrorMessage->setText(QString());
        AddModify->setText(QApplication::translate("AddAccount", "Add / Modify", 0));
        Delete->setText(QApplication::translate("AddAccount", "Delete", 0));
        pushButton->setText(QApplication::translate("AddAccount", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAccount: public Ui_AddAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACCOUNT_H
