/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(640, 460);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217/VK_Compact_Logo (1) (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(133, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 20px"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(50, 30, 50, 30);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 20, -1, 20);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName("verticalLayout_4");
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 211, 239);\n"
"border-radius: 5px"));
        lineEdit->setFrame(false);

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 25));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 211, 239);\n"
"border-radius: 5px"));
        lineEdit_2->setFrame(false);

        verticalLayout_4->addWidget(lineEdit_2);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout_5->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Segoe UI\";"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setToolTipDuration(1);
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217/vk-2 (1).png")));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 119, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px"));

        gridLayout_5->addWidget(pushButton, 4, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(132, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 640, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "VKdesktop", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264 \320\222\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\265", nullptr));
        label_4->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
