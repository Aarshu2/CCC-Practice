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

int main () {
    string a, b, c;
    char damn [91];
    for (int i = 0; i < 91; ++i)
    	damn[i] = '.';
    getline(cin, a);
    getline(cin, b);
    for (size_t i = 0; i < a.length(); ++i)
    	damn[b[i]] = a[i];
    getline(cin, c);
    for (size_t i = 0; i < c.length(); ++i) {
    		cout << damn[c[i]];
    }
}