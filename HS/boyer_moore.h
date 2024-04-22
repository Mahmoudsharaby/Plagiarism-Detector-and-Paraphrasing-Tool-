#ifndef boyer_moore_h
#define boyer_moore_h
#include <iostream>
#include <string>
#include "Database.h"
#include"HS/dict.h"

# define NO_OF_CHARS 1000
using namespace std;
class Boyer_Moore_algorithm
{
private:
    string text_in_report = "";
    bool Isplagiarized = 0;
    bool Iseverplagiarized= 0;
    string text;
    string pattern;
    int bad_chars[NO_OF_CHARS];
    Database_handler *documents_for_search = new Database_handler(1);

    void bad_chars_filler()
    {
        int i;
     
        // Initialize all occurrences as -1
        for (i = 0; i < NO_OF_CHARS; i++)
            bad_chars[i] = -1;
     
        // Fill the actual value of last occurrence
        // of a character
        for (i = 0; i < pattern.size(); i++)
            bad_chars[(int) pattern[i]] = i;
    }
    void preprocess_strong_suffix(int *shift, int *bpos)
    {
        int i=pattern.size();
        int j=pattern.size()+1;
        bpos[i]=j;
      
        while(i>0)
        {
            while(j<=pattern.size() && pattern[i-1] != pattern[j-1])
            {
                if (shift[j]==0)
                    shift[j] = j-i;
                j = bpos[j];
            }
            i--;j--;
            bpos[i] = j;
        }
    }
    void process_case_2(int *shift, int *bpos)
    {
        int i, j;
        j = bpos[0];
        for(i=0; i<=pattern.size(); i++)
        {
            if(shift[i]==0)
                shift[i] = j;
            if (i==j)
                j = bpos[j];
        }
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
                if(tokens[i] == tokens[tokens.size()-1]){text_in_report +=("\n The context of the plagiarized text \n" + tokens [i-2] + tokens[i-1] + tokens[i]+ '.');}
                if(tokens[i] == tokens[0]){text_in_report +=("\n The context of the plagiarized text \n" + tokens [i] + tokens[i+1] + tokens[i+2]+ '.');}
                else {text_in_report +=("\n The context of the plagiarized text \n" + tokens [i-1] + tokens[i] + tokens[i+1]+ '.');}
            }
             }
     }


public:
    void search_method_1(string doc_name)
    {
        int m = pattern.size();
        int n = text.size();
        bad_chars_filler();
     
        int s = 0;
        while(s <= (n - m))
        {
            int j = m - 1;
            while(j >= 0 && pattern[j] == text[s + j])
                j--;
     
            if (j < 0)
            {
                Isplagiarized = 1;
                Iseverplagiarized = 1;
                text_in_report += "\n\nPattern ( " + pattern + " )occurs at the document named: ";
                text_in_report += doc_name+'\n';
                s += (s + m < n)? m-bad_chars[text[s + m]] : 1;
                if(pattern[0] == ' '){print_in_context(pattern);}
                else{print_in_context(" " +pattern);}
            }
     
            else
                s += max(1, j - bad_chars[text[s + j]]);
        }
    }
    void search_method_2(string doc_name)
    {
        int s=0, j;
        int m = pattern.size();
        int n = text.size();
      
        int bpos[m+1], shift[m+1];
      
        
        for(int i=0;i<m+1;i++) shift[i]=0;
      
        preprocess_strong_suffix(shift, bpos);
        process_case_2(shift, bpos);
      
        while(s <= n-m)
        {
      
            j = m-1;
            while(j >= 0 && pattern[j] == text[s+j])
                j--;
      
            if (j<0)
            {   
                Isplagiarized = 1;
                Iseverplagiarized = 1;
                s += shift[0];
                text_in_report  += "\n\nPattern ( "+ pattern + " )occurs at the document named " + doc_name+ '\n';
                if(pattern[0] == ' '){print_in_context((pattern));}
                else{print_in_context(" " +pattern);}
                
            }
            else
                s += shift[j+1];
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
    void process_text(int key){
        Iseverplagiarized = 0;
        for(int i = 0; i < documents_for_search->get_num_docs(); i++){
            text = documents_for_search->get_content_by_indx(i);
            text += ' ';
            if(key == 1){search_method_1(documents_for_search->get_doc_name(i));}
            if(key == 2){search_method_2(documents_for_search->get_doc_name(i));}
        }
        if(Iseverplagiarized){
            Paraphrasing_tool * paraphraser = new Paraphrasing_tool();
            text_in_report+=("\n\n Here are some suggestions to avoid plagiarism\n1. consider quoting and in-text citing.\n2. You can paraphrase and in-text cite the source like that (Author Name, year of publication).  \n \nHere is a sample of paraphrased text using our parapharsing tool: "+paraphraser->process_text(pattern));
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

#endif
