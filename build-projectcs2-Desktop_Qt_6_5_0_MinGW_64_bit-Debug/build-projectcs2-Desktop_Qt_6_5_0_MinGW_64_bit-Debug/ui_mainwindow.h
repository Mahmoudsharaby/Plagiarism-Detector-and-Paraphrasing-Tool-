/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton_7;
    QComboBox *comboBox_2;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QSlider *SpeakerSpeed;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1217, 655);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font.setPointSize(12);
        font.setBold(true);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setInputMethodHints(Qt::ImhMultiLine);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(810, 120, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(810, 70, 100, 32));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(170, 10, 103, 32));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(280, 10, 71, 31));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(20, 10, 141, 31));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 60, 781, 201));
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"color: black;\n"
"background: white;\n"
"}"));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setEnabled(true);
        plainTextEdit_2->setGeometry(QRect(20, 270, 891, 301));
        SpeakerSpeed = new QSlider(centralwidget);
        SpeakerSpeed->setObjectName("SpeakerSpeed");
        SpeakerSpeed->setGeometry(QRect(500, 20, 160, 22));
        SpeakerSpeed->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 10, 111, 31));
        label->setTextFormat(Qt::AutoText);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(970, 570, 100, 32));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(980, 10, 141, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(940, 120, 251, 351));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Emoji")});
        font1.setPointSize(11);
        font1.setBold(false);
        textEdit->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1217, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        centralwidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Voice 1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Voice 2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Voice 3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Voice 4", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Voice 5", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Voice 6", nullptr));

        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Brute Force", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "KMP", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Rabin Karp", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Boyer Moore 1", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "Boyer Moore 2", nullptr));

        plainTextEdit->setPlainText(QString());
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter The Content of The Document Here", nullptr));
        plainTextEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Your Answer Will Appear Here", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Speaker Speed: ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Developer Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
