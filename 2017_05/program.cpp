#define ROWS 200
#define COLUMNS 320

#include <iostream>
#include <fstream>

using namespace std;

uint16_t pixels[ROWS][COLUMNS];

void LoadData(){
    ifstream in("Dane_PR/dane.txt");
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            in>>pixels[i][j];
        }
    }
    in.close();
}
bool has_contrast(int y, int x){
    // Column
    if (y > 0 && abs(pixels[y][x] - pixels[y - 1][x]) > 128) return true;
    if (y < ROWS - 1 && abs(pixels[y][x] - pixels[y + 1][x]) > 128) return true;
    // Row
    if (x > 0 && abs(pixels[y][x] - pixels[y][x - 1]) > 128) return true;
    if (x < COLUMNS - 1 && abs(pixels[y][x] - pixels[y][x + 1]) > 128) return true;

    return false;
}

int main(){
    LoadData();
    ofstream out("wyniki6.txt");
    
    // 6.1
    uint16_t nj = 0, nc = 256;
    for(int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            if (pixels[i][j] > nj) nj = pixels[i][j];
            if (pixels[i][j] < nc) nc = pixels[i][j];
        }
    }
    out<<"Zadanie 6.1\n"<<nj<<" "<<nc<<"\n\n";

    // 6.2
    int ctr = 0;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            if (pixels[i][j] == pixels[i][COLUMNS - j - 1]) continue;
            ctr++;
            break;
        }
    }
    out<<"Zadanie 6.2\n"<<ctr<<"\n\n";

    // 6.3
    int contrastcount = 0;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            if (has_contrast(i, j)) contrastcount++;
        }
    }
    out<<"Zadanie 6.3\n"<<contrastcount<<"\n\n";

    // 6.4
    int llen = -1, brightness, len;
    for (int i = 0; i < COLUMNS; i++){
        brightness = pixels[0][i];
        len = 1;
        for (int j = 1; j < ROWS; j++){
            if (pixels[j][i] == pixels[j - 1][i]){
                len++;
                continue;
            }
            if (len > llen){
                llen = len;
            }
            brightness = pixels[j][i];
            len = 1;
        }
    }
    out<<"Zadanie 6.4\n"<<llen<<"\n";
    out.close();
    return 0;
}