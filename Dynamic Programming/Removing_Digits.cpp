#include <iostream>
#include <vector>
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
    vector<int> dp(n+1, 0);
    for(int x = 1; x <= n; x++) {
        int ans = 1e9;
        int a = x;
        while(a > 0) {
            int d = a % 10;
            a /= 10;
            if(d) ans = min(ans, 1 + dp[x-d]);
        }
        dp[x] = ans;
    }
    int ans = dp[n];
    cout << ans << endl;
    return 0;
}

// tc - O(n log n)
// sc - O(n)