#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int inv2 = 5e8 + 4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int totSum = (n * (n+1)) / 2;
    if(totSum & 1) {
        cout << 0 << '\n';
        return 0;
    } 
    int sum = totSum / 2;
    vector<int> prev(sum+1, 0);
    prev[0] = 1;
    for(int i = 1; i < n; i++) {
        for(int s = sum; s >= 1; s--) {
            int notPick = prev[s];
            int pick = 0;
            if(i <= s) pick = prev[s - i];
            prev[s] = (notPick + pick) % MOD;
        }
    }
    int ans = prev[sum];
    cout << ans << '\n';
    return 0;
}

// tc - O(n * sum)
// sc - O(sum)