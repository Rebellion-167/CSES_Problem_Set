#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;

#define ll long long
#define nl '\n'

vector<ll> fact(MAX), inv_fact(MAX);

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for(ll i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    inv_fact[MAX - 1] = binpow(fact[MAX - 1], mod - 2);

    for(ll i = MAX - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
    }
}

void solve() { 
    ll a, b;
    cin >> a >> b;

    ll ans = fact[a];
    ans = (ans * inv_fact[b]) % mod;
    ans = (ans * inv_fact[a - b]) % mod;
    cout << ans << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}

// TC - O(1e6 + n)
// SC - O(1e6)