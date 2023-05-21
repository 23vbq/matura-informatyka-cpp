#include <iostream>
#include <fstream>

using namespace std;

string odszyfr(string s, int k){
    int c;
    string buffer = "";
    for (int i = 0; i < s.size(); i++){
        c = ((int)(s[i] - 'A') - k) % 26;
        if (c < 0) c += 26;
        c += 'A';
        buffer += c;
    }
    return buffer;
}

int main(){
    ifstream in("Dane_NOWA/dane_6_2.txt");
    ofstream out("wyniki_6_2.txt");
    string line, szyfrogram;
    int k = 0;
    while (getline(in, line)){
        szyfrogram = line.substr(0, line.find(' '));
        if (line.substr(line.find(' ') + 1) != "")
            k = stoi(line.substr(line.find(' ') + 1));
        else k = 107;
        out<<odszyfr(szyfrogram, k)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}