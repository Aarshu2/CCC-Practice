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

int main() {
    unordered_map<char, int> m1 = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    string numbers;
    cin >> numbers;

    int final = 0;
    for (int i = 0; i < numbers.size(); i += 2) {
        int a = numbers[i] - '0'; 
        int r = m1[numbers[i + 1]];           
        int pair_value = a * r;

        if (i + 3 < numbers.size() && m1[numbers[i + 3]] > r) {
            final -= pair_value;             
        } else {
            final += pair_value;            
        }
    }

    cout << final << endl;

    return 0;
}