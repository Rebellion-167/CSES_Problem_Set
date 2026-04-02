#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
#define nl '\n'
 
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> arr;
    for(ll i = 0; i < n; i++) {
        ll st, et;
        cin >> st >> et;
        arr.push_back({st, et});
    }

    sort(arr.begin(), arr.end(), [](const pair<ll, ll> &p1, 
    const pair<ll, ll> &p2) {
        return p1.second < p2.second;
    });

    multiset<ll> times;
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        auto it = times.upper_bound(arr[i].first);
        if(it != times.begin()) {
            --it;
            times.erase(it);
            times.insert(arr[i].second);
            cnt++;
        } else if((int)times.size() < k) {
            times.insert(arr[i].second);
            cnt++;
        }
    }

    cout << cnt << nl;
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