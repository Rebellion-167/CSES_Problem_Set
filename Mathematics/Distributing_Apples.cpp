#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

const int mod = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> fact(n+m+1), inv_fact(n+m+1);
    fact[0] = 1;
    for(ll i = 1; i <= n+m; i++) {
        fact[i] = fact[i-1] * i % mod;
    }

    inv_fact[n+m] = binpow(fact[n+m], mod-2);

    for(ll i = n + m - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % mod;
    }

    ll ans = fact[n + m - 1];
    ans = (ans * inv_fact[m]) % mod;
    ans = (ans * inv_fact[n - 1]) % mod;
    cout << ans << nl;
    return;
}

int main() {
    solve();
    return 0;
}

// TC - O(n + m)
// SC - O(n + m)