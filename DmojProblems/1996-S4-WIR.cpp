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
string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

bool valid(char a, char b) {
    if(a == 'I' && (b == 'V' || b == 'X')) {
        return true;
    } else if(a == 'X' && (b == 'L' || b == 'C')) {
        return true;
    } else if(a == 'C' && (b == 'D' || b == 'M')) {
        return true;
    }
    return false;
}

int romanToInt(string s) {
    int ans = 0;
    for(int i = 0; i < s.size() - 1; i++) {
        char a = s[i];
        char b = s[i + 1];
        if(valid(a, b)) {
            ans += (romans[b] - romans[a]);
            i++;
        } else {
            ans += romans[a];
        }
    }
}

string intToRoman(int num) {
    string ans;
    for(int i = 0; i < 13; i++) {
        if((num - numbers[i]) > 0) {
            ans += romans[i];
            num -= romans[i];
        }
    }

    return ans;
}

int main() {
    int n; 
    cin >> n;
    while(n--) {
        string p, f, s;
        cin >> p;
        for(int i = 0; i < p.size() - 1; i++) {
            if(p[i] != '+') {
                f += p[i];
            } else {
                i++;
                s += p[i];
            }
        }
        int sum = romanToInt(s) + romanToInt(f);
        if(sum > 1000) {
            cout << "CONCORDIA CUM VERITATE" << endl;
        } else {
            cout << intToRoman(sum) << endl;
        }
    }
    return 0;
}