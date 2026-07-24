#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int s = 1; s <= x; s++) {
        int ways = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] <= s) ways = (ways + dp[s - arr[i]]) % MOD;
        }
        dp[s] = (ways % MOD);
    }

    int ans = dp[x];
    cout << ans << endl;
    return 0;
}

// tc - O(n * x)
// sc - O(x)