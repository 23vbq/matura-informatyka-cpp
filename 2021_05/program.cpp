#define OPTIONS_COUNT 2000

#include <iostream>
#include <fstream>

using namespace std;

string buffer = "";
string options[OPTIONS_COUNT];

void Dopisz(char letter){
    buffer += letter;
}
void Zmien(char letter){
    buffer[buffer.size() - 1] = letter;
}
void Usun(){
    buffer.pop_back();
}
void Przesun(char letter){
    for(int i = 0; i < buffer.size(); i++){
        if (buffer[i] == letter){
            letter++;
            if (letter > 'Z') letter = 'A';
            buffer[i] = letter;
            return;
        }
    }
}
void LoadOptions(){
    ifstream in("DANE_2105/instrukcje.txt");
    string line;
    int i = 0;
    while(getline(in, line)){
        options[i] = line;
        i++;
    }
}
void HandleOption(string option){
    int spacepos = option.find(' ');
    string opt = option.substr(0, spacepos);
    string arg = option.substr(spacepos + 1);
    
    if (opt == "DOPISZ") { Dopisz(arg[0]); return; }
    if (opt == "ZMIEN") { Zmien(arg[0]); return; }
    if (opt == "USUN") { Usun(); return;}
    if (opt == "PRZESUN") { Przesun(arg[0]); return;}
}

int main(){
    LoadOptions();
    for (int i = 0; i < OPTIONS_COUNT; i++){
        //cout<<i<<" > "<<options[i]<<"\n";
        HandleOption(options[i]);
    }
    ofstream out("wyniki4.txt");

    // 4.1
    out<<"Zadanie 4.1\n"<<buffer.size()<<"\r\n";
    
    // 4.2
    int same_opt_count = 1, najw_same_opt_count = -1;
    string last_opt = options[0].substr(0, options[0].find(' '));
    string opt_buff, najw_same_opt;
    for (int i = 1; i < OPTIONS_COUNT; i++){
        opt_buff = options[i].substr(0, options[i].find(' '));
        if (last_opt == opt_buff) same_opt_count++;
        else{
            if (same_opt_count > najw_same_opt_count){
                najw_same_opt_count = same_opt_count;
                najw_same_opt = last_opt;
            }
            same_opt_count = 1;
            last_opt = opt_buff;
        }
    }
    out<<"Zadanie 4.2\n"<<najw_same_opt<<" "<<najw_same_opt_count<<"\r\n";

    // 4.3
    int char_count[26] = {0};
    for (int i = 0; i < OPTIONS_COUNT; i++){
        int spacepos = options[i].find(' ');
        string opt = options[i].substr(0, spacepos);
        string arg = options[i].substr(spacepos + 1);
        if (opt != "DOPISZ") continue;
        char_count[arg[0] - 'A']++;
    }
    //for(int i = 0; i < 26; i++) cout<<(char)('A' + i)<<" - "<<char_count[i]<<"\n";
    int najw_char_count = -1;
    int najw_char;
    for (int i = 0; i < 26; i++){
        if (char_count[i] > najw_char_count){
            najw_char_count = char_count[i];
            najw_char = i;
        }
    }
    out<<"Zadanie 4.3\n"<<(char)('A' + najw_char)<<" "<<najw_char_count<<"\r\n";

    // 4.4
    out<<"Zadanie 4.4\n"<<buffer;
    out.close();
    return 0;
}