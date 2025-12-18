#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];

    ll maxLen = 0;
    ll l = 0, r = 0;
    map<ll, ll> mpp;
    while(r < n) {
        if(mpp.count(arr[r]))
            l = max(l, mpp[arr[r]] + 1);
        
        mpp[arr[r]] = r;
        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    cout << maxLen << nl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(nlogn)
// sc - O(n)