#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

#define ll long long
#define nl '\n'

ll f(ll n, vector<ll> &dp) {
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll ans = 0;
    for(ll i = 1; i <= 6; i++) {
        if(n - i >= 0) ans = (ans + f(n-i, dp)) % MOD;
    }
    return dp[n] = ans % MOD;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    ll ans = f(n, dp);
    cout << ans % MOD << nl;
    return 0;
}

// tc - O(n * 6)
// tc - O(n) + O(n)