#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<string>> dp(n, vector<string>(n, ""));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == n - 1 and j == n - 1)
                dp[i][j] = string(1, arr[i][j]);
            else {
                string down = "~", right = "~";
                if(i+1 < n) down = dp[i+1][j];
                if(j+1 < n) right = dp[i][j+1];
                dp[i][j] = arr[i][j] + min(down, right);
            }
        }
    }
    string ans = dp[0][0];
    cout << ans << endl;
    return 0;
}