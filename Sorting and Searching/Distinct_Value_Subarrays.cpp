#include <iostream>
#include <vector>
#include <map>

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

    ll count = 0;
    map<ll, ll> mpp;
    ll l = 0, r = 0;
    while(r < (int)arr.size()) {
        if(mpp.count(arr[r])) {
            l = max(l, mpp[arr[r]] + 1);
        }
        mpp[arr[r]] = r;
        count += (r - l + 1);
        r++;
    }

    cout << count << nl;
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