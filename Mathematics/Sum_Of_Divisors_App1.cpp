#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MOD 1000000007

ll naturalSum(ll n) {
    // returns (n * (n+1)) / 2

    ll a, b;
    if(n & 1) {
        a = n, b = (n+1)/2;
    } else {
        a = n/2, b = n+1;
    }

    return ((a % MOD) * (b % MOD)) % MOD;
}
int main() {
    ll n;
    cin >> n;

    ll sum = 0;
    for(ll x = 1; x*x <= n; x++) {
        ll cnt = n/x - x + 1;
        sum += (cnt % MOD) * x;
        sum %= MOD;
        sum += naturalSum(n/x) - naturalSum(x);
        sum += MOD;
        sum %= MOD;
    }

    cout << sum << '\n';
    return 0;
}

// TC - O(sqrt(N))
// SC - O(1)