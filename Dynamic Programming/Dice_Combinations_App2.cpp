#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

#define ll long long
#define nl '\n'

int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll d = 1; d <= 6; d++) {
            if(i - d >= 0) {
                dp[i] = (dp[i] + dp[i-d]) % MOD;
            }
        }
    }
    cout << dp[n] << nl;
    return 0;
}

// tc - O(n * 6)
// tc - O(n)