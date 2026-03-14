#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + arr[i-1];
    }

    map<ll, ll> mpp;
    ll cnt = 0;
    for(int i = 0; i <= n; i++) {
        if(mpp.find(pref[i] - x) != mpp.end()) {
            cnt += mpp[pref[i] - x];
        }
        mpp[pref[i]]++;
    }
    cout << cnt << '\n';
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