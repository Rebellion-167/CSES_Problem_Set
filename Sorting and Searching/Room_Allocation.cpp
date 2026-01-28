#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
#define nl '\n'
#define sp ' '
#define ppi pair<pair<int, int>, int>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<ppi> arr;
    for(int i = 0; i < n; i++) {
        int st, et;
        cin >> st >> et;
        arr.push_back({{st, et}, i});
    }

    sort(arr.begin(), arr.end());

    multiset<pii> et;
    ppi temp = arr[0];
    vector<int> assigned(n);
    assigned[temp.second] = 1;
    et.emplace(temp.first.second, 1);

    for(int i = 1; i < n; i++) {
        temp = arr[i];

        pii smallest = *et.begin();

        if(smallest.first < temp.first.first) {
            et.erase(et.begin());
            assigned[temp.second] = smallest.second;
            et.emplace(temp.first.second, smallest.second);
        } else {
            assigned[temp.second] = et.size() + 1;
            et.emplace(temp.first.second, assigned[temp.second]);
        }
    }

    cout << *max_element(assigned.begin(), assigned.end()) << nl;
    for(auto room : assigned) {
        cout << room << sp;
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

// time complexity - O(n log n)
// space complexity - O(n)