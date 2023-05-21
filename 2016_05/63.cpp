#include <iostream>
#include <fstream>

using namespace std;

bool isInvalid(string t, string s){
    int diff, a, b, lastdiff;
    for (int i = 0; i < t.size(); i++){
        a = (int)(t[i] - 'A');
        b = (int)(s[i] - 'A');
        diff = b;
        if (a > b) diff += 26 - a;
        else diff -= a;
        if (diff != lastdiff && i != 0) return true;
        lastdiff = diff;
    }
    return false;
}

int main(){
    ifstream in("Dane_NOWA/dane_6_3.txt");
    ofstream out("wyniki_6_3.txt");
    string line, slowo, szyfrogram;
    while (getline(in, line)){
        slowo = line.substr(0, line.find(' '));
        szyfrogram = line.substr(line.find(' ') + 1);
        if(isInvalid(slowo, szyfrogram))
            out<<slowo<<"\n";
    }
    in.close();
    out.close();
    return 0;
}