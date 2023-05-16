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
int PrintDobreTrojki(){
    ofstream tout("trojki.txt");
    int count = 0;
    int x, y, z;
    for (int i = 0; i < 200; i++){
        x = number_buffer[i];
        for (int j = 0; j < 200; j++){
            y = number_buffer[j];
            if (y == x) continue;
            if (y % x != 0) continue;
            for (int k = 0; k < 200; k++){
                z = number_buffer[k];
                if (z == y || z == x) continue;
                if (z % y != 0) continue;
                tout<<x<<" "<<y<<" "<<z<<"\n";
                count++;
            }
        }
    }
    return count;
}
int DobrePiatki(){
    int count = 0;
    int u, w, x, y, z;
    for (int i = 0; i < 200; i++){
        u = number_buffer[i];
        for (int j = 0; j < 200; j++){
            w = number_buffer[j];
            if (w == u) continue;
            if (w % u != 0) continue;
            for (int k = 0; k < 200; k++){
                x = number_buffer[k];
                if (x == w || x == u) continue;
                if (x % w != 0) continue;
                for (int l = 0; l < 200; l++){
                    y = number_buffer[l];
                    if (y == x || y == w || y == u) continue;
                    if (y % x != 0) continue;
                    for (int m = 0; m < 200; m++){
                        z = number_buffer[m];
                        if (z == y || z == x || z == w || z == u) continue;
                        if (z % y != 0) continue;
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main(){
    LoadFile();
    ofstream out("wyniki4.txt", ios::app);
    out<<"Zadanie 4.3\na) "<<PrintDobreTrojki()<<"\nb) "<<DobrePiatki()<<"\n";
    out.close();
    return 0;
}