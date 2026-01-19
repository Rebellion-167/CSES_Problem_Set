#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define nl '\n'
#define sp ' '

struct Interval {
    ll start;
    ll end;
    ll index;

    Interval(ll s, ll e, ll idx) : start(s), end(e), index(idx) {};
};

bool comp(Interval& a, Interval& b) {
    if(a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

void solve() {
    ll n;
    cin >> n;

    vector<Interval> arr;
    for(int i = 0; i < n; i++) {
        ll start, end;
        cin >> start >> end;
        arr.emplace_back(start, end, i);
    }

    sort(arr.begin(), arr.end(), comp);

    vector<int> is_contained(n, 0);
    vector<int> contains_some(n, 0);

    ordered_multiset<int> ets;
    for(int i = 0; i < n; i++) {
        auto& current = arr[i];
        int lb = ets.order_of_key(arr[i].end);
        is_contained[current.index] = ets.size() - lb;
        ets.insert(arr[i].end);
    }

    ets.clear();
    for(int i = n - 1; i >= 0; i--) {
        auto& current = arr[i];
        int ub = ets.order_of_key(arr[i].end + 1);
        contains_some[current.index] = ub;
        ets.insert(arr[i].end);
    }

    for(int i = 0; i < n; i++) {
        cout << contains_some[i] << sp;
    }
    cout << nl;
    for(int i = 0; i < n; i++) {
        cout << is_contained[i] << sp;
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