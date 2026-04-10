#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    vector<ll> prefix(n+1, 0);
    for(ll i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + arr[i-1];

    while(q--) {
        ll a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
    }
    return 0;
}

// tc - O(n + q)
// sc - O(n)