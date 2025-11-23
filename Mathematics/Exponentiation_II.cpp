#include <iostream>
using namespace std;

#define ll long long
#define nl '\n'
#define MOD 1000000007

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while(b > 0) {
        if(b & 1)  
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll res1 = binpow(b, c, MOD-1);
    ll res2 = binpow(a, res1, MOD);

    cout << res2 << nl;
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