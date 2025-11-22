#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long

void solve() {
    ll k;
    cin >> k;
    ll d = 1;
    ll start = 1;
    while(true) {
        ll blocks = (ll)9 * start * d;

        if(k > blocks) {
            k -= blocks;
            d++;
            start *= 10;
        } else {
            break;
        }
    }

    ll number_idx = (k - 1) / d;
    ll digit_idx = (k - 1) % d;
    ll number = start + number_idx;

    string num = to_string(number);
    cout << num[digit_idx] << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}

// tc - O(q) for q queries
// sc - O(1)