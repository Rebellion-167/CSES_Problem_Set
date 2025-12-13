#include <bits/stdc++.h>
using namespace std;

#define sp ' '
#define nl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    ll median = arr[n/2];

    ll ans = 0;
    for(auto x : arr) {
        ans += abs(median - x);
    }

    cout << ans << '\n';
    return 0;
}

// tc - O(nlogn)
// sc - O(1)