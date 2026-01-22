#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define nl '\n'
#define sp ' '

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    ordered_set nums;
    for(int i = 1; i <= n; i++) {
        nums.insert(i);
    }

    int pos = 0;
    while(!nums.empty()) {
        pos = (pos + k) % nums.size();
        auto it = nums.find_by_order(pos);
        cout << *it << sp;
        nums.erase(it);
    }
    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

// time complexity - O(n log n)
// space complexity - O(n)