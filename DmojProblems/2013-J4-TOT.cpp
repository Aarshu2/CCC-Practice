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
    int minutes; cin >> minutes;
    int chores; cin >> chores;
    vector<int> nums;

    while(chores--) {
        int currChoreTime; cin >> currChoreTime;
        nums.push_back(currChoreTime);
    }

    sort(nums.begin(), nums.end());

    int i = 0;
    int total = 0;
    int count = 0;
    while(true) {
        total += nums[i++];
        if(total > minutes) {
            break;
        }
        else {
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}