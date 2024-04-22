#ifndef Database
#define Database
#include <vector>
#include <iostream>
#include <QString>
#include <fstream>
#include <QFile>
#include <qlabel.h>
#include <QTextStream>

using namespace std;
class Database_handler{
    
    vector <QString> document_names;
    vector <QString> documents_content;

     int get_indx(QString nm){
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
        //QLabel *testLabel= new QLabel;
        QString line;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&file);

            while (!in.atEnd()){
                line = in.readLine();
                qDebug().nospace() << "IN WHILE " << qPrintable(line);
                //testLabel->setText(line+"\n");
                add_documents(line);
            }
        }
        file.close();
    }
    public:
    void get_data(){
        QString name_f;
        QFile r;
        for(int i = 0; i < document_names.size();i++){
            name_f = "";
            name_f += "files\\";
            name_f += document_names[i];
            name_f += ".txt"; 

        if (r.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&name_f);
            QString s , Text="";
            while(!in.atEnd()){
                s = in.readLine();
                Text+=s;
            }
            r.close();
            documents_content.push_back(Text); 
        }
    }}

    Database_handler(int k){
        if(k == 1){
        Read_Data();}
    }

      void add_documents(QString filename){
        document_names.push_back(filename);
        }
    

      void remove_documents(QString filename){
        vector <QString>:: iterator it;
        it = document_names.erase(document_names.begin()+get_indx(filename));
    }
     /*void print_recent_docs(){
        for(int i = 0; i < document_names.size();i++){
            cout << document_names[i] << endl;
        }
    }*/
     /*void print_recent_docs_content(){
        for(int i = 0; i < documents_content.size();i++){
            cout << documents_content[i] << endl;
        }
    }*/
     int get_num_docs(){
        return document_names.size();
    }

    QString get_content_by_indx(int indx){
    for(int i = 0; i < documents_content.size();i++){
        if(i == indx){return documents_content[i];}
    }
        return "";
    }
     QString get_doc_name(int indx){
    for(int i = 0; i < document_names.size();i++){
        if(i == indx){return document_names[i];}
    }
    return "";
    }
    };


#endif
