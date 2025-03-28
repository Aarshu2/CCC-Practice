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
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for(int i = 0; i < int(b.length()); i++){
        if(b[i]==' ') b.erase(i, 1);
    }
    for(int i = 0; i < int(a.size());i++){
        if(a[i]==' ') a.erase(i, 1);
    }
    for(int i = 0; i < int(a.length()); i++){
        for(int j = 0; j < int(b.length()); j++){
            if(a[i] == b[j]){
                b.erase(j, 1);
                break;
            }
        }
    }
    (b.size()>0)?cout << "Is not an anagram.":cout << "Is an anagram.";
    return 0;

}