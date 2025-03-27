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
    vector<string> first, second;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++){
            string s; cin >> s;
            i==0?first.push_back(s):second.push_back(s);
        }
    }
    if(n%2==1){
        cout << "bad";
        return 0;
    }
    for(int i = 0; i < n; i++){
        auto it = find(second.begin(), second.end(), first[i]);
        int position = distance(second.begin(), it);
        if(!(first[position]==second[i]) || position == i){
            cout << "bad";
            return 0;
        }
    }
    cout << "good";
    return 0;
}