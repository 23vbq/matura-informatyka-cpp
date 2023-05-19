#define ROWS 100

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int pair_number[ROWS];
string pair_string[ROWS];

void LoadData(){
    ifstream in("Dane_PR2/pary.txt");
    string line;
    int i = 0;
    while (getline(in, line)){
        pair_number[i] = stoi(line.substr(0, line.find(' ')));
        pair_string[i] = line.substr(line.find(' ') + 1);
        i++;
    }
}
bool czy_pierwsza(int n){
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}
pair<int, int> SumOfTwoPierwszych(int n){
    // Ustalenie jakie sa sumy
    vector<int> sumElements;
    for (int i = 2; i < n; i++){
        if (!czy_pierwsza(i)) continue;
        for (int j = i; j < n; j++){
            if (!czy_pierwsza(j)) continue;
            if (i + j != n) continue;
            sumElements.push_back(i);
            sumElements.push_back(j);
        }
    }
    // Znalezienie o najwiekszej roznicy
    int firstIndex, maxDiff = -1, diff;
    for(int i = 0; i < sumElements.size(); i += 2){
        diff = sumElements[i + 1] - sumElements[i];
        if (diff > maxDiff){
            firstIndex = i;
            maxDiff = diff;
        }
    }
    return pair<int, int>(sumElements[firstIndex], sumElements[firstIndex + 1]);
}
pair<int, int> LongestFragment(string s){
    int offset = 0, length = 1;
    int loffs, llen = -1;
    for (int i = 1; i < s.length(); i++){
        if (s[i] == s[i - 1]){
            length++;
        } else{
            if (length > llen){
                loffs = offset;
                llen = length;
            }
            offset = i;
            length = 1;
        }
    }
    if (length > llen){
        loffs = offset;
        llen = length;
    }
    return pair<int, int>(loffs, llen);
}

int main(){
    LoadData();
    ofstream out("wyniki4.txt");
    /*for(int i = 0; i < ROWS; i++){
        cout<<pair_number[i]<<" => "<<pair_string[i]<<"\n";
    }*/

    // 4.1
    out<<"Zadanie 4.1\n";
    pair<int, int> sumoftwo;
    for(int i = 0; i < ROWS; i++){
        if (pair_number[i] % 2 != 0) continue;
        sumoftwo = SumOfTwoPierwszych(pair_number[i]);
        out<<pair_number[i]<<" "<<sumoftwo.first<<" "<<sumoftwo.second<<"\n";
    }

    // 4.2
    out<<"\nZadanie 4.2\n";
    pair<int, int> lonfrag;
    for (int i = 0; i < ROWS; i++){
        lonfrag = LongestFragment(pair_string[i]);
        out<<pair_string[i].substr(lonfrag.first, lonfrag.second)<<" "<<lonfrag.second<<"\n";
    }

    // 4.3
    out<<"\nZadanie 4.3\n";
    int smallestPairIndex = -1;
    for (int i = 0; i < ROWS; i++){
        if (pair_number[i] != pair_string[i].length()) continue;
        if (smallestPairIndex == -1) { smallestPairIndex = i; continue; }

        if (pair_number[i] < pair_number[smallestPairIndex]){
            smallestPairIndex = i;
            continue;
        }
        for (int j = 0; j < pair_string[i].length(); j++){
            if (pair_string[i][j] == pair_string[smallestPairIndex][j]) continue;
            if (pair_string[i][j] < pair_string[smallestPairIndex][j]){
                smallestPairIndex = i;
                break;
            }
        }
    }
    out<<pair_number[smallestPairIndex]<<" "<<pair_string[smallestPairIndex]<<"\n";
    out.close();
    return 0;
}