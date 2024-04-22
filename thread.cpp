#include <windows.h>
#include "HS/thread.h"
#include <QtCore>
#include <QDebug>

using namespace  std;
void mythread::run(){
qDebug() << "Running";
}
void mythread::SPEAK(string text_to_say){
    string command = "espeak -v +f6 -s1000 \"" + text_to_say + "\"";
    const char * charcommand = command.c_str();
    system(charcommand);
}
