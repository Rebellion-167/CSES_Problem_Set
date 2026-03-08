#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    ll maxi = *max_element(arr.begin(), arr.end());

    cout << max(sum, 2LL * maxi) << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(N)
// sc - O(1)