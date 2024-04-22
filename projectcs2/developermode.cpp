#include "developermode.h"
#include "ui_developermode.h"
#include "mainwindow.h"
#include "HS/dict.h"
developermode::developermode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::developermode)
{
    ui->setupUi(this);
    ui->gridLayoutWidget->hide();
}

developermode::~developermode()
{
    delete ui;
}

void developermode::on_pushButton_3_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

void developermode::on_pushButton_clicked()
{
    QString entered_pass = ui->lineEdit->text();
    bool Res_Log = para->compare_hashes(entered_pass.toStdString());
    if(Res_Log){
    ui->gridLayoutWidget->show();
    ui->label->setStyleSheet("QLabel { color : green; }");
    ui->label->setText("Access Granted !");
    }
    else{
        ui->label->setStyleSheet("QLabel { color : red; }");
        ui->label->setText("Access Denied. Try Again !");
    }
}


void developermode::on_pushButton_2_clicked()
{
para->Add_To_Database(ui->lineEdit_2->text().toStdString() , ui->lineEdit_3->text().toStdString(), ui->lineEdit_4->text().toStdString());
ui->label_2->setStyleSheet("QLabel { color : green; }");
ui->label_2->setText("Added successfully");
}

