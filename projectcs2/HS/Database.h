#ifndef Database
#define Database
#include <vector>
#include <iostream>
#include <QString>
#include <fstream>
#include <QFile>
#include <qlabel.h>
#include <QTextStream>
#include <QVector>
#include <QDir>
#include <QDebug>


using namespace std;
class Database_handler{

    QVector <string> document_names;
    QVector <string> documents_content;

    void add_documents(string FN){
        document_names.push_back(FN);
        }

    int get_indx(string nm){
        int indx;
        for(int i = 0; i < document_names.size(); i++){
            if (document_names[i] == nm){
                indx = i;
            }
        }
        return indx;
    }


     void Read_Data(){

         QFile file("D:\\SPRING 2023\\CS 2\\project\\QT\\projectcs2\\HS\\files\\filenames.txt");
         if(file.open(QIODevice::ReadOnly)) {
         QTextStream stream(&file);

         while(!stream.atEnd()) {
             //cout << stream.readLine().toStdString() << endl;
             document_names.push_back(stream.readLine().toStdString());
         }
         file.close();
         }

         }
    public:
    void get_data(){
        QString name_f;

        for(int i = 0; i < document_names.size();i++){
            name_f = "";
            name_f += "D:\\SPRING 2023\\CS 2\\project\\QT\\projectcs2\\HS\\files\\";
            name_f += document_names[i];
            name_f += ".txt";

        QFile r(name_f);

        if (r.open(QIODevice::ReadOnly)){
            QTextStream in(&r);
            QString Text="";
            while(!in.atEnd()){
                Text+=in.readLine();
            }
            documents_content.push_back(Text.toStdString());
            r.close();
        }
    }}

    Database_handler(int k){
        if(k == 1){
        Read_Data();
        get_data();
        }
    }

    void remove_documents(string filename){
        QVector <string>:: iterator it;
        it = document_names.erase(document_names.begin()+get_indx(filename));
    }
     void print_recent_docs(){
        for(int i = 0; i < document_names.size();i++){
            cout << document_names[i] << endl;
        }
    }

     int get_num_docs(){
        return document_names.size();
    }

    string get_content_by_indx(int indx){
    for(int i = 0; i < documents_content.size();i++){
        if(i == indx){return documents_content[i];}
    }
        return "";
    }
    string get_doc_name(int indx){
    for(int i = 0; i < document_names.size();i++){
        if(i == indx){return document_names[i];}
    }
    return "";
    }
    };


#endif
