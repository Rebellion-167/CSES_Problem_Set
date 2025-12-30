#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n;
    cin >> n;

    vector<ll> th;
    for(ll i = 0; i < n; i++) {
        ll h;
        cin >> h;

        if(th.empty() || h >= th.back())
            th.push_back(h);
        else {
            auto it = upper_bound(th.begin(), th.end(), h);
            *it = h;
        }
    }

    cout << th.size() << nl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n log n)
// sc - O(n)