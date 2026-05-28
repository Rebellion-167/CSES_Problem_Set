#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ordered_multiset ms;
    for(int i = 0; i < k; i++) ms.insert({arr[i], i});
    for(int i = k; i < n; i++) {
        auto md = *ms.find_by_order((k - 1) / 2);
        cout << md.first << ' ';
        ms.erase({arr[i-k], i-k});
        ms.insert({arr[i], i});
    }
    auto md = *ms.find_by_order((k - 1) / 2);
    cout << md.first << ' ';
    cout << '\n';
    return 0;
}

// tc - O(n log k)
// sc - O(k)