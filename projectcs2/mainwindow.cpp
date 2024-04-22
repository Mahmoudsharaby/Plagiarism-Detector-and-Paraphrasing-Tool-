#include <windows.h>
#include "developermode.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSyntaxHighlighter"
#include <QTextEdit>
#include "HS/boyer_moore.h"
#include "HS/KMP.h"
#include "HS/brute_force_algorithm.h"
#include "HS/rabin.h"
#include <QVector>
#include <QCoreApplication>
#include "developer_mode.h"
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->plainTextEdit->setPlainText("");
    ui->plainTextEdit_2->setPlainText("");
}
void Display_INFO(Ui::MainWindow * u,int exe_time , int alg_indx , double percentage){

percentage *=100.0;

if(alg_indx == 0){
    u->textEdit->setText("Here are some analysis of the Brute Force algorithm:\nComplexity: O(n*m)\nn: Size of pattern.\nm: Size of text.\n\nTime Taken for execution: " + QString::number(exe_time) + " nanoseconds."+'\n' + "The percentage of plagiarism in this document is: " + QString::number(percentage)+ '%');
}
else if(alg_indx == 1){
    u->textEdit->setText("Here are some analysis of the KMP algorithm:\nComplexity: O(n+m)\nn: Size of pattern.\nm: Size of text.\n\nTime Taken for execution: " + QString::number(exe_time) + " nanoseconds."+'\n' + "The percentage of plagiarism in this document is: " + QString::number(percentage)+ '%');
}
else if(alg_indx == 2){
    u->textEdit->setText("Here are some analysis of the Rabin Karp algorithm:\nComplexity: O(n*m)\nn: Size of pattern.\nm: Size of text.\n\nTime Taken for execution: " + QString::number(exe_time) + " nanoseconds."+'\n' + "The percentage of plagiarism in this document is: " + QString::number(percentage)+ '%');
}
else if(alg_indx == 3 || alg_indx == 4){
    u->textEdit->setText("Here are some analysis of the Boyer Moore algorithm:\nComplexity: O(n*m)\nn: Size of pattern.\nm: Size of text.\n\nTime Taken for execution: " + QString::number(exe_time) + " nanoseconds."+'\n' + "The percentage of plagiarism in this document is: " + QString::number(percentage)+ '%');
}
}
void MainWindow::on_pushButton_2_clicked(){

    string pattern = ui->plainTextEdit->toPlainText().toStdString();

    QVector <string> tokens;

    stringstream check1(pattern);

    string intermediate;

    while(getline(check1, intermediate, '.'))
        {
            tokens.push_back(intermediate);
        }

double num_sents_plagiarized;
double total_sent_number;


if(ui->comboBox_2->currentIndex() == 0){
    QString text_to_display;

    Brute_Force_alg b1;
    num_sents_plagiarized = 0.0;
    total_sent_number = 0.0;
    int time_ex;
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    for(int i = 0; i < tokens.length(); i++){

        tokens[i]+='.';
        b1.set_pattern(tokens[i]);
        b1.process_text();

        if(b1.get_result() == true){num_sents_plagiarized =num_sents_plagiarized + 1.0;}
        total_sent_number = total_sent_number + 1.0;
        QString ss =  QString::fromStdString(b1.get_text_in_rep());
        text_to_display+=ss;
    }

    std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
    time_ex = std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();

    ui->plainTextEdit_2->setPlainText(text_to_display);
    Display_INFO(ui , time_ex , ui->comboBox_2->currentIndex() , num_sents_plagiarized/total_sent_number);
}

else if(ui->comboBox_2->currentIndex() == 1){
    QString text_to_display;
    num_sents_plagiarized = 0.0;
    total_sent_number = 0.0;
    int time_ex;
    KMP_algorithm k1;
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    for(int i = 0; i < tokens.length(); i++){
    tokens[i]+='.';
    k1.set_pattern(tokens[i]);
    k1.process_text();
    if(k1.get_result()){
        num_sents_plagiarized+=1.0;
    }
    total_sent_number+=1.0;
    QString ss =  QString::fromStdString(k1.get_text_in_rep());
    text_to_display+=ss;
    }
    std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
    time_ex = std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();
    Display_INFO(ui , time_ex , ui->comboBox_2->currentIndex() , num_sents_plagiarized/total_sent_number);
    ui->plainTextEdit_2->setPlainText(text_to_display);
}
else if(ui->comboBox_2->currentIndex() == 3 || ui->comboBox_2->currentIndex() == 4){

    QString text_to_display;
    Boyer_Moore_algorithm bm;
    int time_ex;
    num_sents_plagiarized = 0.0;
    total_sent_number =0.0;
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

    for(int i = 0; i < tokens.length(); i++){
    tokens[i]+='.';
    bm.set_pattern(tokens[i]);
    bm.process_text(ui->comboBox_2->currentIndex()-2);
    if(bm.get_result()){
        num_sents_plagiarized +=1.0;
    }
    total_sent_number += 1.0;
    QString ss =  QString::fromStdString(bm.get_text_in_rep());
    text_to_display+=ss;
    }
    std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
    time_ex = std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();
    Display_INFO(ui , time_ex , ui->comboBox_2->currentIndex() , num_sents_plagiarized/total_sent_number);
    ui->plainTextEdit_2->setPlainText(text_to_display);
}


else{
    QString text_to_display;
    Rabin_Karp_algorithm r1;
    int time_ex;
    num_sents_plagiarized = 0.0;
    total_sent_number = 0.0;

    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    for(int i = 0; i < tokens.length(); i++){
    tokens[i]+='.';
    r1.set_pattern(tokens[i]);
    r1.process_text();
    if(r1.get_result() == true){
        num_sents_plagiarized+=1.0;
    }
    total_sent_number += 1.0;
    QString ss =  QString::fromStdString(r1.get_text_in_rep());
    text_to_display+=ss;
    }
    std::chrono::steady_clock::time_point then = std:: chrono::steady_clock::now();
    time_ex = std::chrono::duration_cast<std::chrono::nanoseconds> (then - now).count();
    Display_INFO(ui , time_ex , ui->comboBox_2->currentIndex() , num_sents_plagiarized/total_sent_number);
    ui->plainTextEdit_2->setPlainText(text_to_display);
}
}
string prepare_text_for_espeak(string x) {
    string res = "";
    for(int i = 0; i < x.length(); i++){
        if(x[i] == '\n'){
            res += ' ';
        }
        else{
            res += x[i];
        }
    }
    return res;
}

void speakT(int key , int speed ,string text_to_say){
int c = 0;
string command = "espeak -v +f"+ to_string(key) + " -s" + to_string(speed) + " \""+ text_to_say + "\"";
const char * charcommand = command.c_str();
if (system(charcommand) == 1){
if(c + 8000 > text_to_say.length()){
return speakT(key , speed, text_to_say.substr(c , text_to_say.length()));
}
else{
    c+=8000;
    return speakT(key , speed, text_to_say.substr(c-8000 , c));
}
}
}

void MainWindow::on_pushButton_7_clicked()
{
    QString text_to_say = ui->plainTextEdit_2->toPlainText();
    speakT(ui->comboBox->currentIndex()+1,ui->SpeakerSpeed->value()*1.4+80 , prepare_text_for_espeak(text_to_say.toStdString()));
}

void MainWindow::on_pushButton_3_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_4_clicked()
{
    developermode *d1 = new developermode();
    d1->show();
    this->close();
}

