#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n+1);
    for(ll i = 1; i <= n; i++) cin >> arr[i];

    vector<ll> p_sum(n+1, 0);
    multiset<ll> ms;
    ll ans = -1e18;
    for(ll i = 1; i <= n; i++) {
        p_sum[i] = p_sum[i-1] + arr[i];
        if(i < a) continue;
        ms.insert(p_sum[i-a]);
        if(i > b) ms.erase(ms.find(p_sum[i-b-1]));
        ans = max(ans, p_sum[i] - *begin(ms));
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

// TC - O(n*logn)
// SC - O(n)