#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll prefix = 0;
    ll i;
    for(i = 0; i < n; i++) {
        if(arr[i] <= prefix+1)
            prefix += arr[i];
        else 
            break;
    }

    cout << prefix+1 << nl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n log n)
// sc - O(n)