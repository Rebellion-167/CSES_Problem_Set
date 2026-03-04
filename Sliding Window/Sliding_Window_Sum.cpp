#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b;
    cin >> x >> a >> b;
    ll c;
    cin >> c;

    vector<ll> arr(n);
    arr[0] = x;
    for(ll i = 1; i < n; i++)
        arr[i] = (a * arr[i-1] + b) % c;

    // for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    ll currSum = 0;
    for(ll i = 0; i < k; i++)
        currSum += arr[i];

    ll ans = 0;
    for(ll i = k; i < n; i++) {
        ans ^= currSum;
        currSum += arr[i];
        currSum -= arr[i - k];
    }
    ans ^= currSum;

    cout << ans << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(N) where N is the size of the array
// sc - O(1)