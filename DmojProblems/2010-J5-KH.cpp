#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstdio>
#include <format>
#include <climits>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int,int> moves[8] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    bool vis[10][10] = {false};
    int dist[10][10] = {0}; 

    int startR, startC, endR, endC; 
    cin >> startR >> startC;
    cin >> endR >> endC;

    queue<pair<int, int>> bfs;
    bfs.push({startR, startC});
    vis[startR][startC] = true;

    while(!bfs.empty()) {
        auto cur = bfs.front(); bfs.pop();
        if(cur.first == endR and cur.second == endC) {
            cout << dist[endR][endC] << endl;
            break;
        } else {
            for(auto &dir : moves) {
                int r = cur.first + dir.first;
                int c = cur.second + dir.second;
                if(r < 1 || r > 8 || c < 1 || c > 8 || vis[r][c]) {
                    continue;
                }
                dist[r][c] = dist[cur.first][cur.second] + 1;
                vis[r][c] = true;
                bfs.push({r, c});
            }
        }
    }


    return 0;
}