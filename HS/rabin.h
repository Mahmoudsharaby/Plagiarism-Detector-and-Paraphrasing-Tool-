#ifndef rabin
#define rabin
#include "Database.h"
#include <bits/stdc++.h>
#include <HS/dict.h>
#define d 1000

using namespace std;
// d is the number of characters in the input alphabet

class Rabin_Karp_algorithm{
bool Isplagiarized = 0;
bool Iseverplagiarized = 0;
string text_in_report = "";
string pattern, text;
Database_handler * documents_for_search = new Database_handler(1);



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

void run_rabin_karp(string doc_name)
{
	int q = INT_MAX;
	int M = pattern.length();
	int N = text.length();
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for text
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++) {
        p =pattern[i]+p; 								    //(d * p + pattern[i]) % q;
        t =text[i]+t; 									    //(d * t + text[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (text[i + j] != pattern[j]) {
					break;
				}
			}

			// if p == t and pattern[0...M-1] = text[i, i+1,
			// ...i+M-1]

			if (j == M){
				Isplagiarized = 1;
                Iseverplagiarized = 1;
                text_in_report  += ("\n\nPattern " +pattern+  "has been found at the document named: " + doc_name  + '\n');
				if(pattern[0] == ' '){print_in_context((pattern));}
                else{print_in_context(" " +pattern);}
;}
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = (t-text[i]);//(d * (t - text[i] * h) + text[i + M]) % q;
			t += text[i+M];
			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

void set_pattern(string pattern_to_set) {pattern = pattern_to_set;}
void set_text(string text_to_set) {text = text_to_set;}
string get_text(){
    return text;
}
string get_pattern(){
    return pattern;
}

void process_text(){
        Iseverplagiarized = 0;
        for(int i = 0; i < documents_for_search->get_num_docs(); i++){
            text = documents_for_search->get_content_by_indx(i);
            text += ' ';
            run_rabin_karp(documents_for_search->get_doc_name(i));
        }
        if(Iseverplagiarized){
        Paraphrasing_tool * paraphraser= new Paraphrasing_tool();
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
#endif
