#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstdio>
#include <format>
#include <initializer_list>
#include <unordered_set>
#include <set>
#include <cmath>
#include <queue>

using namespace std;
int main() {
  int testcases;
  cin >> testcases;
  
  for(int i = 0; i < testcases; i++) {
    int h, w;
    cin >> h >> w;
    cin.ignore();

    bool vis[25][25] = {false};
    string map[25];
    for(int j = 0; j < h; j++) {
      getline(cin, map[j]);
    }

    int x = 0, y = 0;
    vis[x][y] = true;
    queue<tuple<int, int, int>> bfs;
    bfs.push({x, y, 1});
    bool found = false;

    while(!bfs.empty()) {
      auto curr = bfs.front();bfs.pop();
      x = get<0>(curr);
      y = get<1>(curr);
      if(x == h - 1 && y == w - 1) {
        cout << get<2>(curr) << endl;
        found = true;
      } else {
        char cur = map[x][y];
        if((cur == '+' || cur == '-') && y + 1 < w && !vis[x][y + 1] && map[x][y + 1] != '*') { // right
          bfs.push({x, y+1, get<2>(curr) + 1});
          vis[x][y + 1] = true;
        }
        if((cur == '+' || cur == '-') && y - 1 >= 0 && !vis[x][y - 1] && map[x][y - 1] != '*') { // left
          bfs.push({x, y-1, get<2>(curr) + 1});
          vis[x][y - 1] = true;
        }
        if((cur == '+' || cur == '-') && x + 1 < h && !vis[x + 1][y] && map[x + 1][y] != '*') { // down
          bfs.push({x + 1, y, get<2>(curr) + 1});
          vis[x + 1][y] = true;
        }
        if((cur == '+' || cur == '-') && x - 1 >= 0 && !vis[x - 1][y] && map[x - 1][y] != '*') { // up
          bfs.push({x - 1, y, get<2>(curr) + 1});
          vis[x - 1][y] = true;
        }
      }

    }

    if(!found){
      cout << -1 << endl;
    }
  }

  return 0;
}