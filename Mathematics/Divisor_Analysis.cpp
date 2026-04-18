#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define ll long long
#define sp ' '
#define nl '\n'

const int MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

ll mod_inv(ll a) {
    return binpow(a, MOD-2);
}

void solve() {
    ll n;
    cin >> n;
    
    ll num_div = 1;
    ll sum_div = 1;
    ll prod_div = 1;

    ll exp = 1;

    while(n--) {
        ll x, k;
        cin >> x >> k;

        num_div = num_div * (k+1) % MOD;
        
        ll term = (binpow(x, k+1) - 1 + MOD) % MOD;
        term = term * mod_inv(x - 1) % MOD;
        sum_div = sum_div * term % MOD;
        
        prod_div = binpow(prod_div, k + 1) * binpow(binpow(x, k * (k+1) / 2 % (MOD - 1)), exp) % MOD;

        exp = exp * (k+1) % (MOD - 1);
    }

    cout << num_div << sp;
    cout << sum_div << sp;
    cout << prod_div << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// TC - O(n log MOD)
// SC - O(1)