#ifndef THREAD_H
#define THREAD_H
#include <QtCore>
#include<QApplication>
#include <iostream>
using namespace std;
class mythread:public QThread{
public:
    void run();
    void SPEAK(std::string);
    void cont();
};
#endif // THREAD_H
