#define NUM_COUNT 100

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int numbers[NUM_COUNT];
vector<int> l_pierwsze;

void LoadData(){
    ifstream in("Dane_2212/liczby.txt");
    int a, i = 0;
    while(in>>a){
        numbers[i] = a;
        i++;
    }
    in.close();
}
bool czy_pierwsza(int n){
    if (n < 2)
        return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}
void pierwszeDoLiczby( int n){
    int i = 0;
    if (l_pierwsze.size()) i = l_pierwsze.back();
    for (; i < n; i++)
        if (czy_pierwsza(i)) l_pierwsze.push_back(i);
}
int sposobyRozkladu(int n){
    vector<int> pierwsze;
    pierwszeDoLiczby( n);
    int sposoby = 0, ps = l_pierwsze.size();
    int lastPierwszaIdx = ps - 1;
    while(l_pierwsze[lastPierwszaIdx] > n) lastPierwszaIdx--;
    for (int i = 0; i <= lastPierwszaIdx; i++){
        for (int j = i; j <= lastPierwszaIdx; j++){
            if (l_pierwsze[i] + l_pierwsze[j] == n){
                sposoby++;
                break;
            }
        }
    }
    return sposoby;
}
void countHex(int* hexCount, int n){
    while (n){
        hexCount[n % 16]++;
        n /= 16;
    }
}

int main(){
    LoadData();
    ofstream out("wyniki3.txt");

    // 3.2
    int pierwszecount = 0;
    for (int i = 0; i < NUM_COUNT; i++){
        if (czy_pierwsza(numbers[i] - 1)) pierwszecount++;
    }
    out<<"Zadanie 3.2\n"<<pierwszecount<<"\n\n";

    // 3.3
    int max_rl, max_rc = -1, min_rl, min_rc = 2147483647;
    for (int i = 0; i < NUM_COUNT; i++){
        if (numbers[i] > 2 && numbers[i] % 2 == 0){
            int rc = sposobyRozkladu(numbers[i]);
            if (rc > max_rc){
                max_rc = rc;
                max_rl = numbers[i];
            }
            if (rc < min_rc){
                min_rc = rc;
                min_rl = numbers[i];
            }
            cout<<"PASS3.3 => "<<i<<"\n";
        }
    }
    out<<"Zadanie 3.3\n"<<max_rl<<" "<<max_rc<<" "<<min_rl<<" "<<min_rc<<"\n\n";
    cout<<"PASS3.3"<<"\n";

    // 3.4
    int hexCount[16] = {0};
    for (int i = 0; i < NUM_COUNT; i++){
        countHex(hexCount, numbers[i]);
    }
    out<<"Zadanie 3.4\n";
    for (int i = 0; i < 16; i++){
        out<<(i < 10 ? (char)(i + '0') : (char)(i + 'A' - 10))<<":"<<hexCount[i]<<"\n";
    }
    out.close();
    cout<<"PASS3.4"<<"\n";
    return 0;
}