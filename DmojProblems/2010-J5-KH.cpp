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

using namespace std;

int main() {
    int startR, startC, endR, endC;
    cin >> startR >> startC >> endR >> endC;
    startR--; startC--; // Converting to 0-based index for easier handling
    endR--; endC--;

    queue<pair<int, int>> q;
    q.push({startR, startC});
    
    vector<vector<bool>> vis(8, vector<bool>(8, false));
    vis[startR][startC] = true;

    int moves = 0;
    bool found = false;

    vector<vector<int>> dirs = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    while(!q.empty() && !found) {
        int size = q.size(); // Number of nodes at current BFS level
        
        for (int i = 0; i < size; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if(r == endR && c == endC) { // If we reach the target position
                found = true;
                break;
            }
            
            for (auto dir : dirs) {
                int row = r + dir[0];
                int col = c + dir[1];
                
                if (row >= 0 && row < 8 && col >= 0 && col < 8 && !vis[row][col]) {
                    vis[row][col] = true;
                    q.push({row, col});
                }
            }
        }
        
        if (!found) moves++; // Increment move count after finishing each BFS level
    }

    cout << moves << endl;
    return 0;
}