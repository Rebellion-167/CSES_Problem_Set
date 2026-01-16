#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long
#define nl '\n'
#define sp ' '

struct Interval {
    ll start;
    ll end;
    ll original_index;

    Interval(ll s, ll e, ll idx) : start(s), end(e), original_index(idx) {}
};

bool comp(Interval& a, Interval& b) {
    if(a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

void solve() {
    ll n;
    cin >> n;
    vector<Interval> arr;
    for(ll i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        arr.emplace_back(start, end, i);
    }

    sort(arr.begin(), arr.end(), comp);

    vector<int> is_contained(n, 0);
    vector<int> contains_some(n, 0);

    ll run_max = INT_MIN;
    for(ll i = 0; i < n; i++) {
        auto& current = arr[i];
        if(run_max != INT_MIN and current.end <= run_max) {
            is_contained[current.original_index] = 1;
        }
        run_max = max(run_max, current.end);
    }

    ll run_min = INT_MAX;
    for(ll i = n - 1; i >= 0; i--) {
        auto& current = arr[i];
        if(run_min != INT_MAX and current.end >= run_min) {
            contains_some[current.original_index] = 1;
        }
        run_min = min(run_min, current.end);
    }

    for(ll i = 0; i < n; i++)
        cout << contains_some[i] << sp;
    cout << nl;
    for(ll i = 0; i < n; i++)
        cout << is_contained[i] << sp;
    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// time complexity - O(N log N)
// space complexity - O(N)