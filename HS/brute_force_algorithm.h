#ifndef brute_force_algorithm
#define brute_force_algorithm

#include "Database.h"
#include "dict.h"
#include <bits/stdc++.h>
#include <QVector>


class Brute_Force_alg{
string text_in_report = "";
bool Isplagiarized = 0;
bool Iseverplagiarized = 0;
int Differences = 0;
Database_handler * documents_for_search = new Database_handler(1);

string text,pattern;

int Compute_Hamming_Distance(string one, string two){
    Differences = 0;
    for(int i = 0; i < one.length(); i++){
        if(one[i] != two[i]){Differences++;}
    }
    return Differences;
}

 
void print_in_context(string modified_pattern){
     
    // Vector of string to save tokens
    QVector <string> tokens;
     
    // stringstream class check1
    stringstream check1(text);
     
    string intermediate;
     
    while(getline(check1, intermediate, '.'))
    {
        tokens.push_back(intermediate);
    }

    for(int i = 0; i < tokens.size(); i++){
        tokens[i] += '.';
        //cout << tokens[i] << '\t' << modified_pattern<<endl << endl;
        if(tokens[i][0] != ' '){tokens[i] = ' '+tokens[i];}
        if (tokens[i] == modified_pattern){
            //cout << "\n\nThe context of the plagiarized text\n " << tokens [i-1] + tokens[i]+ tokens [i+1] << endl;
            if(tokens[i] == tokens[tokens.size()-1]){text_in_report +=("\n The context of the plagiarized text \n" + tokens [i-2] + tokens[i-1] + tokens[i]+ '.');}
            if(tokens[i] == tokens[0]){text_in_report +=("\n The context of the plagiarized text \n" + tokens [i] + tokens[i+1] + tokens[i+2]+ '.');}
            else {text_in_report +=("\n The context of the plagiarized text \n" + tokens [i-1] + tokens[i] + tokens[i+1]+ '.');}
        }
         }
 }

public:

void brute_force(string doc_name){
    int n = text.length();
    int m = pattern.length();
    string substring_starting_from_i;
    int res_ham = 0;
    Isplagiarized = 0;
    for(int i = 0; i < ((n-m)+1); i++){
        substring_starting_from_i = text.substr(i,m);
        res_ham = Compute_Hamming_Distance(substring_starting_from_i , pattern);
        //if(doc_name == "reflection_paper_ebram"){cout << res_ham  << ' ' << substring_starting_from_i<< endl;}
        if(res_ham == 0){
            Iseverplagiarized = 1;
            //cout << "\n\nA matching has occured at document named: " << doc_name << endl;
            text_in_report += ("\n\n A matching has occured at document named: " + doc_name + '\n' + "\nFound pattern:" + pattern);
            if(pattern[0] == ' '){print_in_context((pattern));}
            else{print_in_context(' ' + pattern);}
            Isplagiarized = 1;
        }
        }

}
void process_text(){
    Iseverplagiarized = 0;
    for(int i = 0; i < documents_for_search->get_num_docs(); i++){
        text = documents_for_search->get_content_by_indx(i);
        text+= ' ';
        //cout << i << endl;
        brute_force(documents_for_search->get_doc_name(i));
    }
    if(Iseverplagiarized){
        Paraphrasing_tool * paraphraser = new Paraphrasing_tool();
        text_in_report+=("\n\n Here are some suggestions to avoid plagiarism\n1. Consider quoting and in-text citing.\n2. You can paraphrase and in-text cite the source like that (Author Name, year of publication).  \n \nHere is a sample of paraphrased text using our parapharsing tool: "+paraphraser->process_text(pattern)+'\n');
    }
}
    void set_pattern(string p){
        pattern = p;
    }
int get_result(){
    return Iseverplagiarized;
}

string get_text_in_rep(){
    string temp = text_in_report;
    text_in_report = "";
    return temp;
}
};
#endif
