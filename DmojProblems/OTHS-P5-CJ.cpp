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

const int N = 1e3 + 3;
int n, m, ans; char g[N][N]; bool f, vis[N][N] = {};
void dfs(int r, int c) {
    if (r < 1 || n < r || c < 1 || m < c || vis[r][c] || g[r][c] == 'X') return;
    vis[r][c] = 1;
    if (g[r][c] == '*') f = 0;
    dfs(r + 1, c); dfs(r - 1, c);
    dfs(r, c + 1); dfs(r, c - 1);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && g[i][j] == '.') {
                f = 1; 
                dfs(i, j); ans += f;
            }
        }
    }
    cout << ans << "\n";
}