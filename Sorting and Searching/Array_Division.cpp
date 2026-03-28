#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

bool checkSplits(vector<ll> arr, ll n, ll k, ll mid) {
    ll splits = 1;
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] > mid) return false;
        if(sum + arr[i] <= mid) sum += arr[i];
        else {
            splits++; 
            sum = arr[i];
        }
    }
    return (splits <= k);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll low = 1, high = 1e18;
    ll ans;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(checkSplits(arr, n, k, mid)) {
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }

    cout << ans << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n * log (1e18)) ~ O(60 * n)
// sc - O(1)