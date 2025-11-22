#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long

ll josephus(ll n, ll k) {
    // Base case
    if(n == 1) return 1;

    // if k lies within the first half of even numbers
    if(k <= (n+1)/ 2) {
        if(2 * k > n) return (2*k) % n;
        else return 2*k;
    }

    ll temp = josephus(n/2, k - (n+1)/2);
    if(n % 2 == 1) return 2 * temp + 1;
    else return 2 * temp - 1;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = josephus(n, k);
    cout << ans << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}