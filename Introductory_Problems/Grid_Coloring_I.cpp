#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

bool isValid(int i, int j, int n, int m) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) 
        cin >> grid[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            set<char> notAllowed;

            notAllowed.insert(grid[i][j]);
            if(isValid(i, j-1, n, m))
                notAllowed.insert(grid[i][j-1]);
            if(isValid(i-1, j, n, m))
                notAllowed.insert(grid[i-1][j]);

            for(int k = 0; k < 4; k++) {
                char ch = 'A' + k;
                if(notAllowed.find(ch) == notAllowed.end()) {
                    grid[i][j] = ch;
                    break;
                }
            }
        }
    }

    for(auto x : grid) 
        cout << x << nl;
    return 0;
}

// tc - O(n * m)
// sc - O(1)