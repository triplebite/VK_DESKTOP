/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chatroom
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Chatroom)
    {
        if (Chatroom->objectName().isEmpty())
            Chatroom->setObjectName("Chatroom");
        Chatroom->resize(858, 555);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217/VK_Compact_Logo (1) (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        Chatroom->setWindowIcon(icon);
        gridLayout = new QGridLayout(Chatroom);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 20);
        textBrowser = new QTextBrowser(Chatroom);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setStyleSheet(QString::fromUtf8("border-radius: 60px;"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(Chatroom);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Chatroom);
        pushButton->setObjectName("pushButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("release/sendMSG.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Chatroom);

        QMetaObject::connectSlotsByName(Chatroom);
    } // setupUi

    void retranslateUi(QWidget *Chatroom)
    {
        Chatroom->setWindowTitle(QCoreApplication::translate("Chatroom", "VKdesktop chat", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Chatroom: public Ui_Chatroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
