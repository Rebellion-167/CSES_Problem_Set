#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;

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
    ll n;
    cin >> n;

    ll ans = fact[n];
    ll temp_ans = 0;
    int sign = 1;
    for(ll i = n - 1; i >= 0; i--) {
        ll temp = fact[n] * inv_fact[n - i] % mod;
        if(sign == 1) temp_ans = (temp_ans + temp) % mod;
        else temp_ans = (temp_ans - temp + mod) % mod;
        sign = -sign;
    }
    cout << (ans - temp_ans + mod) % mod << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    solve();
    return 0;
}

// tc - O(1e6)
// sc - O(1e6)