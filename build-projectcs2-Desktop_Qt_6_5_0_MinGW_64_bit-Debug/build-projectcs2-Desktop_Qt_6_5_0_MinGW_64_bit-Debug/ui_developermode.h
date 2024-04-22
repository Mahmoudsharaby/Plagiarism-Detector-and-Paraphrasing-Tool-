/********************************************************************************
** Form generated from reading UI file 'developermode.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOPERMODE_H
#define UI_DEVELOPERMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_developermode
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *developermode)
    {
        if (developermode->objectName().isEmpty())
            developermode->setObjectName("developermode");
        developermode->resize(987, 513);
        developermode->setInputMethodHints(Qt::ImhSensitiveData);
        textBrowser = new QTextBrowser(developermode);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(200, 10, 581, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tw Cen MT Condensed Extra Bold")});
        textBrowser->setFont(font);
        pushButton = new QPushButton(developermode);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 130, 75, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        pushButton->setFont(font1);
        gridLayoutWidget = new QWidget(developermode);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 220, 911, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setEnabled(true);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe Script")});
        font2.setPointSize(12);
        lineEdit_3->setFont(font2);

        gridLayout->addWidget(lineEdit_3, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font2);

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(true);
        pushButton_2->setFont(font2);

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(true);
        lineEdit_4->setFont(font2);

        gridLayout->addWidget(lineEdit_4, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(developermode);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(810, 440, 161, 24));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe Script")});
        font3.setPointSize(12);
        font3.setBold(true);
        pushButton_3->setFont(font3);
        lineEdit = new QLineEdit(developermode);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(350, 120, 171, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe Script")});
        font4.setPointSize(11);
        lineEdit->setFont(font4);
        lineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(developermode);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 180, 251, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI")});
        font5.setPointSize(12);
        font5.setBold(true);
        label->setFont(font5);
        label_2 = new QLabel(developermode);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 460, 171, 21));
        label_2->setFont(font5);

        retranslateUi(developermode);

        QMetaObject::connectSlotsByName(developermode);
    } // setupUi

    void retranslateUi(QDialog *developermode)
    {
        developermode->setWindowTitle(QCoreApplication::translate("developermode", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("developermode", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Tw Cen MT Condensed Extra Bold'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:28pt; font-weight:700;\">Welcome in the developer mode</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("developermode", "Login", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("developermode", "Enter Synonym(s)", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("developermode", "Enter New Word", nullptr));
        pushButton_2->setText(QCoreApplication::translate("developermode", "Add Word To Database", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("developermode", "Enter Antynom(s)", nullptr));
        pushButton_3->setText(QCoreApplication::translate("developermode", "Return To Main", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("developermode", "Enter Password", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class developermode: public Ui_developermode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPERMODE_H
