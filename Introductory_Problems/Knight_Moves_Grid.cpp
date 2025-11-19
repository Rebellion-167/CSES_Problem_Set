#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define len(x) int((x).size())

vii offsets = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool is_valid(int i, int j, int n) {
    return i >= 0 and i < n and j >= 0 and j < n;
}
void bfs(vvi &grid, pii start) {
    int n = len(grid);
    queue<pii> q;
    q.push(start);
    int u = start.first;
    int v = start.second;
    grid[u][v] = 0;

    while(!q.empty()) {
        u = q.front().first;
        v = q.front().second;
        q.pop();

        for(auto o : offsets) {
            int x = u + o.first;
            int y = v + o.second;

            if(is_valid(x, y, n) and grid[x][y] == -1) {
                grid[x][y] = grid[u][v] + 1;
                q.push({x, y});
            }
        }
    }
}
int main() {
    int n;
    cin >> n;

    vvi grid(n, vi(n, -1));

    bfs(grid, {0, 0});
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << sp;
        }
        cout << nl;
    }
    return 0;
}