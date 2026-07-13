#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    int len = dp[n][m];
    vector<int> lcs(len);
    int ind = len - 1;
    int i = n, j = m;
    while(i > 0 and j > 0) {
        if(a[i-1] == b[j-1]) {
            lcs[ind] = a[i-1];
            ind--;
            i--, j--; 
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    for(int i = 0; i < len; i++) cout << lcs[i] << ' ';
    cout << '\n';
    return 0;
}

// tc - O(n * m) + O(n + m)
// sc - O(n * m) + O(len)