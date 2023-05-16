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
bool FirstAndLastSame(int n){
    string buffer = to_string(n);
    return buffer[0] == buffer[buffer.size() - 1];
}

int main(){
    LoadFile();
    ofstream out("wyniki4.txt", ios::app);
    int flscount = 0;
    int flsfirstenc = -1;
    for(int i = 0; i < 200; i++){
        if(FirstAndLastSame(number_buffer[i])){
            if(flscount == 0) flsfirstenc = number_buffer[i];
            flscount++;
        }
    }
    out<<"Zadanie 4.1\n"<<flscount<<" "<<flsfirstenc<<"\r\n";
    out.close();
    return 0;
}