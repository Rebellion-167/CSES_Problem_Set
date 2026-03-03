#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

bool check(ll mid, vector<ll>& arr, ll n, ll t) {
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += mid / arr[i];
        if(sum >= t)
            return true;
    }
    return false;
}
void solve() {
    ll n, t;
    cin >> n >> t;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    
    ll mini = *min_element(arr.begin(), arr.end());

    ll low = 1;
    ll high = mini * t;
    ll ans;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(check(mid, arr, n, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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

// tc - O(N * log(t * min(arr)))
// sc - O(1)