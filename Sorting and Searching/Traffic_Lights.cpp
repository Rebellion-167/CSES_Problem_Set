#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long
#define nl '\n'
#define sp ' '

void solve() {
    ll x, n;
    cin >> x >> n;

    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) 
        cin >> arr[i];

    set<ll> pos;
    pos.insert(0);
    pos.insert(x);

    multiset<ll> plens;
    plens.insert(x);

    for(ll i = 0; i < n; i++) {
        auto it = pos.upper_bound(arr[i]);
        ll r = *it;
        --it;
        ll l = *it;
        plens.erase(plens.find(r - l));
        plens.insert(arr[i] - l);
        plens.insert(r - arr[i]);
        cout << *(plens.rbegin()) << sp;
        pos.insert(arr[i]); 
    }
    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n log n)
// sc - O(n)