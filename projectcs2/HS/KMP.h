
#ifndef KMP_h
#define KMP_h

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Database.h"
#include "HS/dict.h"

class KMP_algorithm
{
private:
    string text_in_report = "";
    bool Isplagiarized = 0;
    bool Iseverplagiarized = 0;

    string pattern;
    string text;
    Database_handler *documents_for_search = new Database_handler(1);
    
    void print_in_context(int index){
    //cout << "\nThe context of the searched text in the original text: \n";
    text_in_report+="\nThe context of the searched text in the original text: \n";
    for(int i = 52; i > 0; i--){
        cout << text[index - i];
        text_in_report += text[index - i];
    }
    for(int j = 0; j < 200; j++){
        cout << text[index + j];
        text_in_report += text[index + j];
    }
}

    vector<int> calculate()
    {
        int n = pattern.length();
        vector<int> arr(n, 0);
        int len = 0;
        int i = 1;
        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                arr[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = arr[len - 1];
                }
                else
                {
                    arr[i] = 0;
                    i++;
                }
            }
        }
        return arr;
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
    void kmp(string doc_name)
    {
        int n = text.length();
        int m = pattern.length();
        vector <int> arr = calculate();
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }
            
            if (j == m)
            {
                Isplagiarized = 1;
                Iseverplagiarized = 1;
                text_in_report += "\n\n Found pattern ( " + pattern + " )at document named: " + doc_name+ '\n';
                j = arr[j - 1];
                if(pattern[0] == ' '){print_in_context((pattern));}
                else{print_in_context(" " +pattern);}


            }
            else if (i < n && text[i] != pattern[j])
            {
                if (j != 0)
                {
                    j = arr[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }
    void set_pattern(string n)
    {
        pattern=n;
    }
    void set_text(string k)
    {
        text=k;
    }
    string get_pattern()
    {
        return pattern;
    }
    string get_text()
    {
        return text;
    }
    void process_text(){
        Iseverplagiarized = 0;
        for(int i = 0; i < documents_for_search->get_num_docs(); i++){
            text = documents_for_search->get_content_by_indx(i);
            text += ' ';
            kmp(documents_for_search->get_doc_name(i));
        }
        if(Iseverplagiarized){
            Paraphrasing_tool * paraphraser = new Paraphrasing_tool();
            text_in_report+=("\n\n Here are some suggestions to avoid plagiarism\n1. Consider quoting and in-text citing.\n2. You can paraphrase and in-text cite the source like that (Author Name, year of publication).  \n \nHere is a sample of paraphrased text using our parapharsing tool: "+paraphraser->process_text(pattern)+'\n');
        }
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


#endif /* KMP_h */
