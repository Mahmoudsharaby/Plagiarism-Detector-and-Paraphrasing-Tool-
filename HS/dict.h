#ifndef dict
#define dict
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QTextStream>


using namespace std;

class Paraphrasing_tool{

string text_in_report = "";
QMap <string , string> thesaurs_PD;
string read_sentences,syns_ants,key;
bool k = 0;
ifstream reading_instance;
string tolower_str(string sub){
string res = "";
for(int i = 0 ; i < sub.length();i++){
res += tolower(sub[i]);
}
return res;
}

string Generate_Customized_Hashing(string x){
string hash="";
hash+='&';
hash+=x;
for(int i = 10; i < 14; i++){
hash+=to_string((2023%i));
}
hash+='&';
return hash;
}

public:



bool compare_hashes(string h1){
    QFile file("D:\\SPRING 2023\\CS 2\\project\\thesaurs\\HashofPass.txt");
    string h2;
    if(file.open(QIODevice::ReadOnly)) {
    QTextStream stream(&file);
    h2 = stream.readLine().toStdString();
    }
    file.close();

    //cout << h2<<endl;
    //cout <<Generate_Customized_Hashing(h1)<<endl;

    if (Generate_Customized_Hashing(h1) == h2) {return true;}
    else {return false;}
}

void Add_To_Database(string w, string syns , string ants){
    QFile file("D:\\SPRING 2023\\CS 2\\project\\QT\\projectcs2\\HS\\files\\samp.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
    QTextStream stream(&file);
    stream << (" \n\n500: " + QString::fromStdString(w) + "\n\n" + "Syn:   " + QString::fromStdString(syns) + "\n\n" + "Ant:   " + QString::fromStdString(ants));
    }
    file.close();
}
int Is_In_Dictt(string w){
    cout << w;
    int res = 1;
    if (thesaurs_PD.find(w) == thesaurs_PD.end()){
        res = 0;
    }
    return res;
}


Paraphrasing_tool(){

QFile file("D:\\SPRING 2023\\CS 2\\project\\QT\\projectcs2\\HS\\files\\samp.txt");

if(file.open(QIODevice::ReadOnly)) {
QTextStream stream(&file);

while(!stream.atEnd()) {
    read_sentences = (stream.readLine()).toStdString();
    if(read_sentences.length() < 5 ) {continue;}
    if(tolower(read_sentences.at(3)) >= 'a' && tolower(read_sentences.at(3)) <= 'z'){
    key = tolower_str(read_sentences.substr(3,read_sentences.length()-3));
    k = true;
    }
    if((tolower(read_sentences.at(4)) >= 'a' && tolower(read_sentences.at(4)) <= 'z') && (k == false)){
    key = tolower_str(read_sentences.substr(4,read_sentences.length()-4));
    k = true;
    }
    if((tolower(read_sentences.at(5)) >= 'a' && tolower(read_sentences.at(5)) <= 'z') && (k == false)){
    key = tolower_str(read_sentences.substr(5,read_sentences.length()-5));
    }

    else if (tolower_str(read_sentences.substr(0,3)) == "syn"){
    syns_ants = tolower_str(read_sentences.substr(7,read_sentences.length()-4));
    }

    else if (tolower_str(read_sentences.substr(0,3)) == "ant"){
    syns_ants+=' ';
    syns_ants+= tolower_str(read_sentences.substr(7,read_sentences.length()-3));
    thesaurs_PD.insert(key,syns_ants);
    k = false;
    }
}
file.close();
}

}


string first_token(string n){
	
    //create  a vector of tokens
    
    QVector <string> tokens;
    
    string intermediate_str;
     
    stringstream check(n);
     
     
    // Tokenizing the string of synonyms
    while(getline(check, intermediate_str, ' '))
    {
        tokens.push_back(intermediate_str);
    }
     
    // return one of the synonms to the word. In particular, the first one.
    return tokens[0];
}

string get_synonyms(string n){
    QMap <string, string> :: iterator it;
    string res = n;
    for(it = thesaurs_PD.begin(); it != thesaurs_PD.end(); it++){
    if (it.key() == n){
    res = first_token(it.value());
    }
    }
    return res;
}

void print_dict(){ 
    QMap <string, string> :: iterator it;
    for(it = thesaurs_PD.begin(); it != thesaurs_PD.end() ; it++){
    cout <<it.key() << "  "  << it.value() << endl;
    }
}

string process_text(string n){
    QVector <string> tokens;
     
    // stringstream class check1
    stringstream check1(n);
     
    string intermediate;
     
    // Tokenizing w.reading_instance.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    string new_sent = "";
    for(int i = 0; i < tokens.size(); i++){
        new_sent += get_synonyms(tokens[i]);
        new_sent+=' ';
        text_in_report += get_synonyms(tokens[i]);
        text_in_report += ' ';
    }
    return ('\n'+new_sent+'\n');
}




void DEV_MODE(){
    char response = 'y';
    do{
        cout << "=========================== Welcome in the developer mode ==========================\n";
        cout << "Please enter the access code you should have if you are one of the developers\n";
        string password;
        cin >> password;
        if (compare_hashes(password)){
            cout << "Access Granted !!!\n\n";
            cout << "Choose the process you want to perform\n1. Add New Word to the dictionary";
            int x;
            cin >>x; 
            if(x == 1){
                string w , syns, ants , temp;
                cout << "Enter the new word: ";
                cin >> w;
                if(Is_In_Dictt(w) == 0){
                    cout << "Insert synonms as a string of words. Each of them separated by a space\n";
                    getline(cin , temp);
                    getline(cin , syns);
                    cout << "Insert antynoms as a string of words. Each of them separated by a space\n";
                    getline(cin , ants);
                    thesaurs_PD.insert(w,(syns+' '+ants));
                    Add_To_Database(w , syns , ants);
                    cout << "Inserted successfully";
                    }
                else{
                    cout << "This word does exist";
                }
            }
        }
        else{
            cout << "Access code is invalid ! you can't access the dveloper mode\n";
            cout << "Want to try again? (y/n)\n";
            char x;
            cin >> x;
        }
    }while(response == 'y');

}
bool state(){
    return thesaurs_PD.isEmpty();
}
};
#endif
