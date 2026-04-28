#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

const int MAX = 1e6 + 10;

vector<ll> cnt(MAX), cnt2(MAX);

void solve() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(ll i = 1; i < MAX; i++) {
        for(ll j = i; j < MAX; j += i)
            cnt2[i] += cnt[j];
        cnt2[i] = (cnt2[i] * (cnt2[i] - 1)) / 2;
    }

    for(ll i = MAX - 1; i > 0; i--) {
        for(ll j = 2 * i; j < MAX; j += i)
            cnt2[i] -= cnt2[j]; 
    }

    cout << cnt2[1] << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

// TC - O(MAX log MAX)
// SC - O(MAX)