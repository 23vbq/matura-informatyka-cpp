#include <iostream>
#include <fstream>

using namespace std;

string szyfr(string s, int k){
    int c;
    string buffer = "";
    for (int i = 0; i < s.size(); i++){
        c = ((int)(s[i] - 'A') + k) % 26 + 'A';
        buffer += c;
    }
    return buffer;
}

int main(){
    ifstream in("Dane_NOWA/dane_6_1.txt");
    ofstream out("wyniki_6_1.txt");
    string line;
    while (getline(in, line)){
        out<<szyfr(line, 107)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}