#include <bits/stdc++.h>

using namespace std;

#define len(x) (int)((x).size())
#define nl '\n'
#define ll long long

void divide_apples(vector<ll>& arr, ll& ans, int idx, ll g1, ll g2) {
    if(idx == len(arr)) {
        ans = min(ans, abs(g1 - g2));
        return;
    }

    divide_apples(arr, ans, idx+1, g1 + arr[idx], g2);
    divide_apples(arr, ans, idx+1, g1, g2 + arr[idx]);
    return;
}
int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    ll ans = 1e18;
    int start = 0;
    divide_apples(arr, ans, start, 0, 0);

    cout << ans << nl;
    return 0;
}

// tc - O(2^n)
// sc - O(n)