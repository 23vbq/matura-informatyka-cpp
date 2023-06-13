#define NUM_COUNT 100

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int nums[NUM_COUNT];
int reversed_nums[NUM_COUNT];

void LoadData(){
    ifstream in("DANE/liczby.txt");
    int a, i = 0;
    while(!in.eof()){
        in>>a;
        nums[i] = a;
        i++;
    }
    in.close();
}
int odbicie(int n){
    int x = 0;
    while (n){
        x = x * 10 + n % 10;
        n /= 10;
    }
    return x;
}
bool czy_pierwsza(int n){
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    LoadData();
    ofstream out("wyniki4.txt");

    // Odbicie wszystkich liczb
    for (int i = 0; i < NUM_COUNT; i++){
        reversed_nums[i] = odbicie(nums[i]);
    }

    // 4.1
    out<<"Zadanie 4.1\n";
    for (int i = 0; i < NUM_COUNT; i++){
        if (reversed_nums[i] % 17 == 0) out<<reversed_nums[i]<<"\n";
    }

    // 4.2
    int maxDiff = -1, maxDiffNum;
    for (int i = 0; i < NUM_COUNT; i++){
        int diff = abs(nums[i] - reversed_nums[i]);
        if (diff > maxDiff) { maxDiff = diff; maxDiffNum = nums[i]; }
    }
    out<<"\nZadanie 4.2\n"<<maxDiffNum<<" "<<maxDiff<<"\n\n";

    // 4.3
    out<<"Zadanie 4.3\n";
    for (int i = 0; i < NUM_COUNT; i++){
        if (czy_pierwsza(nums[i]) && czy_pierwsza(reversed_nums[i])) out<<nums[i]<<"\n";
    }

    // 4.4
    unordered_map<int, int> m;
    for (int i = 0; i < NUM_COUNT; i++){
        m[nums[i]]++;
    }
    int p2 = 0, p3 = 0;
    for (const auto& kvp : m){
        if (kvp.second == 2) p2++;
        else if (kvp.second == 3) p3++;
    }
    out<<"\nZadanie 4.4\n"<<m.size()<<" "<<p2<<" "<<p3<<"\n";

    out.close();
    return 0;
}