#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstdio>
#include <format>
#include <initializer_list>
#include <unordered_set>
#include <cmath>

using namespace std;
#define pb push_back

unordered_map<char, int> romans = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

bool valid(char a, char b){
    if(a=='I' && (b=='V' || b=='X')){
        return true;
    }else if(a=='X' && (b=='L' || b=='C')){
        return true;
    }else if(a=='C' && (b=='D' || b=='M')){
        return true;
    }
    return false;
}

int romanToInt(string s){
    int ans = 0;
    for(int i=0; i<int(s.size()); i++){
        char a = s[i];
        if(i<int(s.size())-1){
            char b = s[i+1];
            if(valid(a, b)){
                ans+=romans[b]-romans[a];
                i++;
            }else{
                ans+=romans[a];
            }
        }else{
            ans+=romans[a];
        }
    }
    return ans;
}

string intToRomans(int n){
    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; ++i){
        while(n - values[i] >= 0){
            result += str_romans[i];
            n -= values[i];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        string s, f="", sec="";
        bool found = false;
        cin >> s;
        for(int i=0; i<int(s.size()-1);i++){
            if(found){
                sec+=s[i];
            }else{
                if(s[i]=='+'){
                    found = true;
                    continue;
                }
                f+=s[i];
            }
        }
        cout << s;
        int sum = romanToInt(f) + romanToInt(sec);
        if(sum>1000) cout << "CONCORDIA CUM VERITATE" << endl;
        else{
            cout << intToRomans(sum) << endl;
        }
    }
    return 0;
}