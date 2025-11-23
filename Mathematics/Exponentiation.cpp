#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define MOD 1000000007

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll res = binpow(a, b);
    cout << (res % MOD) << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}