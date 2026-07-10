#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    for(int t = 0; t <= x; t++) {
        if(t % arr[0] == 0) dp[0][t] = t / arr[0];
        else dp[0][t] = 1e9;
    }
    for(int ind = 1; ind < n; ind++) {
        for(int t = 0; t <= x; t++) {
            int notTake = 0 + dp[ind-1][t];
            int take = 1e9;
            if(arr[ind] <= t) take = 1 + dp[ind][t - arr[ind]];
            dp[ind][t] = min(take, notTake);
        }
    }
    int ans = dp[n-1][x];
    if(ans >= 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}

// tc - O(n * x)
// sc - O(n * x)