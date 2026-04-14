#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

#define ll long long

ll sumOfRange(ll a, ll b) {
    ll cnt = (b - a + 1) % MOD;
    ll sum = ((a % MOD) + (b % MOD)) % MOD;

    ll res = (cnt * sum) % MOD;

    if(res % 2 == 0) res /= 2;
    else res = (res + MOD) / 2;

    return res % MOD;
}

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    ll d = 1;

    while(d <= n) {
        ll q = n / d;
        ll r = n / q;

        ll sumD = sumOfRange(d, r);
        ans = (ans + (sumD * (q % MOD)) % MOD) % MOD;

        d = r + 1;
    }

    cout << ans << '\n';
    return 0;
}

// TC - O(sqrt(N))
// SC - O(1)