#ifndef Database
#define Database
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Database_handler{
    
    static vector <string> document_names;
    vector <string> documents_content;

    static int get_indx(string nm){
        int indx;
        for(int i = 0; i < document_names.size(); i++){
            if (document_names[i] == nm){
                indx = i;        
            } 
        }
        return indx;
    }
    
    static void Read_Data(){
        ifstream r;
        r.open("files\\filenames.txt");
        string s;
        while(getline(r,s)){
            add_documents(s);
        }
        r.close();
    }
    public:
    void get_data(){
        string name_f;
        ifstream r;
        for(int i = 0; i < document_names.size();i++){
            name_f = "";
            name_f += "files\\";
            name_f += document_names[i];
            name_f += ".txt"; 
            r.open(name_f);
            string s , Text="";
            while(getline(r,s)){
                Text+=s;
            }
            r.close();
            documents_content.push_back(Text); 
        }
    }

    Database_handler(int k){
        if(k == 1){
        Read_Data();}
    }

    static void add_documents(string filename){
        document_names.push_back(filename);
        }
    

    static void remove_documents(string filename){
        vector <string>:: iterator it;
        it = document_names.erase(document_names.begin()+get_indx(filename));
    }
    static void print_recent_docs(){
        for(int i = 0; i < document_names.size();i++){
            cout << document_names[i] << endl;
        }
    }
     void print_recent_docs_content(){
        for(int i = 0; i < documents_content.size();i++){
            cout << documents_content[i] << endl;
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
vector <string> Database_handler::document_names;


#endif