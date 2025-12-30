#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    multiset<ll> th;

    for(ll i = 0; i < n; i++) {
        auto it = th.upper_bound(arr[i]);
        if(it != th.end()) {
            th.erase(it);
        }
        th.insert(arr[i]);
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