#define ROWS 1000
#define CHARS 50

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string rows[ROWS];

void LoadData(){
    ifstream in("DANE/napisy.txt");
    string line;
    int i = 0;
    while (getline(in, line)){
        rows[i++] = line;
    }
    in.close();
}
bool palindrom(string s){
    string rev = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
        rev += s[i];
    return s == rev;
}

int main(){
    LoadData();
    ofstream out("wyniki4.txt");

    // 4.1
    int count_nums = 0;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < CHARS; j++){
            if (rows[i][j] >= '0' && rows[i][j] <= '9') count_nums++;
        }
    }
    out<<"Zadanie 4.1\n"<<count_nums<<"\n";

    // 4.2
    string haslo1 = "";
    for (int i = 1; i <= CHARS; i++){
        haslo1 += rows[i * 20 - 1][i - 1];
    }
    out<<"Zadanie 4.2\n"<<haslo1<<"\n";

    // 4.3
    string haslo2 = "";
    for (int i = 0; i < ROWS; i++){
        string s = rows[i];
        int n = s.size();
        if (palindrom(s + s[0])) haslo2 += s[(n + 1) / 2];
        else if (palindrom(s[n - 1] + s)) haslo2 += s[(n - 1) / 2];
    }
    out<<"Zadanie 4.3\n"<<haslo2<<"\n";

    // 4.4
    string haslo3 = "";
    int xcount = 0;
    for (int i = 0; i < ROWS; i++){
        int pair = 0;
        for (int j = 0; j < CHARS; j++){
            if (!(rows[i][j] >= '0' && rows[i][j] <= '9')) continue;
            if (pair > 9) pair = rows[i][j] - '0';
            else pair = pair * 10 + (rows[i][j] - '0');
            if (pair >= 65 && pair <= 90){
                haslo3 += (char)pair;
                if ((char)pair == 'X') xcount++;
                if (xcount >= 3) break;
            }
            if (xcount >= 3) break;
        }
    }
    out<<"Zadanie 4.4\n"<<haslo3<<"\n";
    out.close();
    return 0;
}