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

int numLen(const string& stri, int pos) {
    int len = 0;
    while(pos < stri.length() && isdigit(stri[pos])) {
        pos++;
        len++;
    }

    return len;
}

long long rleLen(const string& str) {
    int i = 0;
    long long total = 0;
    while(i < str.length()) {
        if(isalpha(str[i])) {
            int numlen = numLen(str, i + 1);
            string num = str.substr(i + 1, numlen);
            long long curr = stoll(num);
            total += curr;
            i += numlen + 1;
        }
    }

    return total;
}

char findCharAtPosition(const string& s, long long c) {
    long long patternLen = rleLen(s);
  
    c = c % patternLen;

    int i = 0;
    long long min = 0;
    while(i < s.length()) {
        if(isalpha(s[i])) {
            char currChar = s[i];
            int numlen = numLen(s, i + 1);
            string num = s.substr(i + 1, numlen);
            long long curr = stoll(num);
            if(min + curr >  c) {
                return currChar;
            }
            i += numlen + 1;
            min += curr;
        }
    }
    return 'c';
}  


int main() {
    string s;
    long long c;
    cin >> s >> c;

    char result = findCharAtPosition(s, c);
    cout << result << endl;

    return 0;
}