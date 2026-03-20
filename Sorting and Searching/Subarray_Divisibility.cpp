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
    for(ll i = 0; i < n; i++) cin >> arr[i];

    vector<ll> prefix(n+1, 0);
    for(ll i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + arr[i-1];

    map<ll, ll> mpp;
    mpp[0] = 1;
    ll cnt = 0;

    for(ll i = 1; i <= n; i++) {
        ll r = prefix[i] % n;
        if(r < 0) r = (r + n) % n;
        if(mpp.find(r) != mpp.end())
            cnt += mpp[r];

        mpp[r]++;
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

// tc - O(n)
// sc - O(n)