#include <iostream>
#include <vector>
#include <limits.h>
#include <deque>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n);
    arr[0] = x;
    for(ll i = 1; i < n; i++)
        arr[i] = (a * arr[i-1] + b) % c;

    ll ans = 0;
    deque<pair<int, int>> dq;
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(!dq.empty() and dq.back().first > arr[i]) dq.pop_back();
        dq.push_back({arr[i], i});

        if(i - j + 1 < k)
            continue;
        else {
            ans = ans xor dq.front().first;

            if(dq.front().second == j) dq.pop_front();
            j++;
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

// tc - O(N) since we are visiting all the elements in the array
// sc - O(N) for the deque