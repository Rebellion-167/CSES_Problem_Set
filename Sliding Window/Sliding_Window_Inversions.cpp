#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define sp ' '
#define nl '\n'

typedef tree<
    pair<ll, ll>,
    null_type,
    less<pair<ll, ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    ordered_multiset ms;
    ll cnt = 0;
    for(ll i = 0; i < k; i++) {
        cnt += ms.size() - ms.order_of_key({arr[i], i});
        ms.insert({arr[i], i});
    }
    for(ll i = k; i < n; i++) {
        cout << cnt << sp;
        cnt -= ms.order_of_key({arr[i-k], i-k});
        ms.erase({arr[i-k], i - k});
        cnt += ms.size() - ms.order_of_key({arr[i], i});
        ms.insert({arr[i], i});
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

// tc - O(n log k)
// sc - O(k)