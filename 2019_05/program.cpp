#define NUMBERS_COUNT 500

#include <iostream>
#include <fstream>

using namespace std;

int numbers[NUMBERS_COUNT];

void LoadData(){
    ifstream in("Dane_PR/liczby.txt");
    int i = 0;
    while(!in.eof()){
        in>>numbers[i];
        i++;
    }
    in.close();
}
bool is_potega(int n, int pot){
    if (n == 1) return true;
    int a = pot;
    while (a <= n){
        if (a == n) return true;
        a *= pot;
    }
    return false;
}
int silnia(int n){
    if (n == 0) return 1;
    return n * silnia(n - 1);
}
int SumaSilniCyfr(int n){
    int sumaSilni = 0;
    while (n){
        sumaSilni += silnia(n % 10);
        n /= 10;
    }
    return sumaSilni;
}
int NWD(int a, int b){
    int r = a % b;
    if (r == 0) return b;
    return NWD(b, r);
}

int main(){
    LoadData();
    ofstream out("wyniki4.txt");

    // 4.1
    int potcount = 0;
    for (int i = 0; i < NUMBERS_COUNT; i++){
        if (is_potega(numbers[i], 3)) potcount++;
    }
    out<<"Zadanie 4.1\n"<<potcount<<"\n\n";
    
    // 4.2
    out<<"Zadanie 4.2\n";
    for (int i = 0; i < NUMBERS_COUNT; i++){
        if (numbers[i] == SumaSilniCyfr(numbers[i]))
            out<<numbers[i]<<"\n";
    }

    // 4.3
    out<<"\nZadanie 4.3\n";
    // NIE DZIALA
    /*int firstnum = numbers[0], len = 3, d, td;
    int llen = -1, lfirstnum, ld;
    for (int i = 1; i < NUMBERS_COUNT - 1; i++){
        td = NWD(NWD(numbers[i - 1], numbers[i]), numbers[i + 1]);
        if (td == 1){
            firstnum = numbers[i - 1];
            len = 3;
            d = td;
            continue;
        }
        if (td == d){
            len++;
            continue;
        }
        // Break part
        if (len > llen){
            lfirstnum = firstnum;
            llen = len;
            ld = d;
        }
        firstnum = numbers[i - 1];
        len = 3;
        d = td;
        
    }
    out<<lfirstnum<<" "<<llen<<" "<<ld;*/
    out.close();
    return 0;
}