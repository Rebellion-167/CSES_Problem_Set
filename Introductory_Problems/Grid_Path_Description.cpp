#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())
#define vi vector<int>
#define vvi vector<vector<int>>

const int N = 7;
int total_paths = 0;
vvi vis(N, vi(N, 0));
string path;

bool is_inbound(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

void dfs(int x, int y, int step) {
    
    if (step == N * N - 1 || (x == N - 1 && y == 0)) {
        total_paths += (step == N * N - 1 && (x == N - 1 && y == 0));
        return;
    }

    // Boxed-in Optimization
    
    if ((!is_inbound(x - 1, y) || vis[x - 1][y]) && (!is_inbound(x + 1, y) || vis[x + 1][y]))
        if (is_inbound(x, y - 1) && !vis[x][y - 1] && is_inbound(x, y + 1) && !vis[x][y + 1])
            return;


    if ((!is_inbound(x, y - 1) || vis[x][y - 1]) && (!is_inbound(x, y + 1) || vis[x][y + 1]))
        if (is_inbound(x - 1, y) && !vis[x - 1][y] && is_inbound(x + 1, y) && !vis[x + 1][y])
            return;

    // Marking current cell so that it isn't visited again
    vis[x][y] = 1;

    // Try going every possible direction (optimise decision based on 'path')
    // path[steps] == '?'; go every possible direction
    // path[steps] != '?'; only go in that direction
    if (path[step] == '?' || path[step] == 'L')
        if (is_inbound(x, y - 1) && !vis[x][y - 1])
            dfs(x, y - 1, step + 1);

    if (path[step] == '?' || path[step] == 'R')
        if (is_inbound(x, y + 1) && !vis[x][y + 1])
            dfs(x, y + 1, step + 1);

    if (path[step] == '?' || path[step] == 'U')
        if (is_inbound(x - 1, y) && !vis[x - 1][y])
            dfs(x - 1, y, step + 1);

    if (path[step] == '?' || path[step] == 'D')
        if (is_inbound(x + 1, y) && !vis[x + 1][y])
            dfs(x + 1, y, step + 1);

    //* BackTracking: unmark so this cell can be visited in some other path
    vis[x][y] = 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> path;

    dfs(0, 0, 0);

    cout << total_paths << nl;
    return 0;
}

// TC - O(48 * 88418) ~ O(5e6)
// SC - O(48 + 7*7) = O(49)