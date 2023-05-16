#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int number_buffer[200];

void LoadFile(){
    ifstream in("DANE_2205/liczby.txt");
    int i = 0;
    while(!in.eof()){
        in>>number_buffer[i];
        i++;
    }
}
int czynniki(int n, bool rozne){
    int ilosc = 0;
    int ostatnidzielnik = -1;
    int i = 2;
    while(n != 1){
        while(n % i == 0){
            n /= i;
            if(!(ostatnidzielnik == i && rozne)) ilosc++;
            ostatnidzielnik = i;
        }
        i++;
    }
    return ilosc;
}

int main(){
    LoadFile();
    ofstream out("wyniki4.txt", ios::app);
    int md_count = -1, md_number, mdr_count = -1, mdr_num;
    for(int i = 0; i < 200; i++){
        int c = czynniki(number_buffer[i], false);
        int cr = czynniki(number_buffer[i], true);
        if(c > md_count){
            md_count = c;
            md_number = number_buffer[i];
        }
        if(cr > mdr_count){
            mdr_count = cr;
            mdr_num = number_buffer[i];
        }
    }
    out<<"Zadanie 4.2\n"<<md_number<<" "<<md_count<<" "<<mdr_num<<" "<<mdr_count<<"\r\n";
    out.close();
    return 0;
}