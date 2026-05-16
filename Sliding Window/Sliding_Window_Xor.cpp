#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n);
    arr[0] = x;
    for(ll i = 1; i < n; i++) {
        arr[i] = (a * arr[i-1] + b) % c;
    }
    int ans = 0;
    for(ll i = 0; i < k; i++)
        ans = ans ^ arr[i];
    ll ops = n - k + 1;
    vector<ll> result(ops);
    result[0] = ans;
    int l = 0, h = k;
    for(ll i = 1; i < ops; i++) {
        ans = ans ^ arr[l];
        ans = ans ^ arr[h];
        result[i] = ans;
        l += 1;
        h += 1; 
    }
    ll fin_ans = 0;
    for(ll i = 0; i < ops; i++)
        fin_ans = fin_ans ^ result[i];
    cout << fin_ans;
    return 0;
}

// TC - O(n)
// SC - O(n)