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
    int w, n; cin >> w >> n;
    int total = 0;
    int count = 0;
    vector<int> cars;
    while(n--){
        int x; cin >> x;
        cars.push_back(x);
    }
    vector<int> railway;
    for(int i = 0; i < int(cars.size()); i++){
        if(railway.size() < 4){
            if(total+cars[i] <= w){
                railway.push_back(cars[i]);
                total+=cars[i];
                count++;
            }else break;
        }else{
            total-= railway[0];
            railway.erase(railway.begin());
            if(total+cars[i] <= w){
                railway.push_back(cars[i]);
                total+=cars[i];
                count++;
            }else break;
        }
    }
    cout << count;
    return 0;
}