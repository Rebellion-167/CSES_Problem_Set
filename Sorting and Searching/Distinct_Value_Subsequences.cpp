#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ll long long
#define nl '\n'
#define MOD 1000000007

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, ll> mpp;
    for(ll i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    ll cnt = 1;
    for(auto &p : mpp) {
        cnt = cnt * ((p.second + 1) % MOD) % MOD; 
    }

    cout << cnt - 1 << nl;
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