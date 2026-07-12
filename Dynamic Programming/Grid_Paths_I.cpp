#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];
    vector<int> prev(n, 0), curr(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == '*') {
                curr[j] = 0;
                continue;
            }
            if(i == 0 and j == 0) {
                curr[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(i > 0) up = prev[j];
            if(j > 0) left = curr[j-1];
            curr[j] = (up + left) % MOD;
        }
        prev = curr;
    }
    int ans = prev[n-1];
    cout << ans << '\n';
    return 0;
}

// tc - O(n * n)
// sc - O(n)