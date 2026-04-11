#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    vector<ll> p_sum(n+1, 0);
    deque<ll> dq;
    ll ans = -1e18;

    for(ll i = 1; i <= n; i++) {
        p_sum[i] = p_sum[i-1] + arr[i-1];

        if(i < a) continue;

        while(!dq.empty() and dq.back() > p_sum[i-a]) dq.pop_back();

        dq.push_back(p_sum[i-a]);

        if(i > b)
            if(dq.front() == p_sum[i-b-1]) dq.pop_front();

        ans = max(ans, p_sum[i] - dq.front());
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// TC - O(n)
// SC - O(n)