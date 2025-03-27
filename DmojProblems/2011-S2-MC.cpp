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
    int l = n;
    n *= 2;
    vector<char> v1;

    while(n--) {
        char currChar; cin >> currChar;
        v1.push_back(currChar);
    }
    int count = 0;
    for(int i = 0; i < l; i++) {
        if(v1[i] == v1[i + l]) {
            count++;
        }
    }

    cout << count;
}