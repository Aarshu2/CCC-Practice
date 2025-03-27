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

int main(){
    int n; cin >> n;
    string res; 

    map<string, char> m1;

    while (n--) {
        char currChar;
        string currNum; 
        cin >> currChar >> currNum; 
        m1[currNum] = currChar;     
    }

    string Number; cin >> Number;

    string currStr = "";
    for(size_t i = 0; i < Number.size(); i++) {
        currStr += Number[i];
        if(m1.find(currStr) != m1.end()) {
            res += m1[currStr];
            currStr = "";
        }
    }

    cout << res << endl;
}