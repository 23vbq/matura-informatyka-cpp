#define ID_COUNT 200

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string ids[ID_COUNT];
int weights[] = {7, 3, 1};

void LoadData(){
    ifstream in("DANE/identyfikator.txt");
    int i = 0;
    string line;
    while (getline(in, line)){
        ids[i++] = line;
    }
    in.close();
}
int SumOfNumbers(string s){
    int sum = 0, n = s.length();
    for (int i = 3; i < n; i++)
        sum += s[i] - '0';
    return sum;
}
bool isPalindrome(string s){
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] != s[n - i - 1]) return false;
    return true;
}
bool verifyId(string s){
    int ctrl = s[3] - '0';
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += (s[i] - 'A' + 10) * weights[i];
    }
    for (int i = 4; i < 9; i++){
        sum += (s[i] - '0') * weights[(i - 1) % 3];
    }
    return ctrl == sum % 10;
}

int main(){
    LoadData();
    ofstream out("wyniki4_1.txt");

    // 4.1
    vector<int> maxSumsIds;
    int maxSum = 0;
    for (int i = 0; i < ID_COUNT; i++){
        int sum = SumOfNumbers(ids[i]);
        if (sum > maxSum){
            maxSum = sum;
            maxSumsIds.clear();
            maxSumsIds.push_back(i);
        } else if (sum == maxSum) maxSumsIds.push_back(i);
    }
    for(auto const& id : maxSumsIds){
        out<<ids[id]<<"\n";
    }
    out.close();

    // 4.2
    out.open("wyniki4_2.txt");
    for (int i = 0; i < ID_COUNT; i++){
        if (isPalindrome(ids[i].substr(0, 3)) || isPalindrome(ids[i].substr(3)))
            out<<ids[i]<<"\n";
    }
    out.close();

    // 4.3
    out.open("wyniki4_3.txt");
    for (int i = 0; i < ID_COUNT; i++){
        if (!verifyId(ids[i])) out<<ids[i]<<"\n";
    }
    out.close();
    return 0;
}