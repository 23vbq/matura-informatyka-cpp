#define ROWS 1000

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string signals[ROWS];

void LoadData(){
    ifstream in("Dane_PR/sygnaly.txt");
    int i = 0;
    string line;
    while(getline(in, line)){
        signals[i] = line;
        i++;
    }
    in.close();
}
/*int CountLetters(string s, char c){
    int count = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == c) count++;
    return count;
}*/
int DifferentLetters(string s){
    int diffCount = 0;
    for (int i = 0; i < s.size(); i++){
        //if (CountLetters(s, s[i]) == 1) diffCount++;
        if (s.find(s[i], i + 1) == string::npos) diffCount++;
    }
    return diffCount;
}
int LDiffBetweenLetters(string s){
    int diff, ldiff = -1;
    for (int i = 0; i < s.size(); i++){
        for (int j = i; j < s.size(); j++){
            diff = abs(s[i] - s[j]);
            if(diff > ldiff){
                ldiff = diff;
            }
        }
    }
    return ldiff;
}


int main(){
    LoadData();
    ofstream out("wyniki4.txt");

    // 4.1
    string przeslanie = "";
    for (int i = 0; i < ROWS + 1; i += 40){
        if (i == 0) continue;
        przeslanie += signals[i - 1][9];
    }
    out<<"Zadanie 4.1\n"<<przeslanie<<"\n\n";

    // 4.2
    string lbuff;
    int llen = -1, difflett;
    for (int i = 0; i < ROWS; i++){
        difflett = DifferentLetters(signals[i]);
        if (difflett > llen){
            llen = difflett;
            lbuff = signals[i];
        }
    }
    out<<"Zadanie 4.2\n"<<lbuff<<" "<<llen<<"\n\n";

    // 4.3
    out<<"Zadanie 4.3\n";
    for (int i = 0; i < ROWS; i++){
        if (LDiffBetweenLetters(signals[i]) > 10) continue;
        out<<signals[i]<<"\n";
    }
    out.close();
    return 0;
}