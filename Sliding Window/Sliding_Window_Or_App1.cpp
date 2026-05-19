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
    vector<ll> prefix(n), suffix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        if(i % k == 0)
            prefix[i] = arr[i];
        else    
            prefix[i] = prefix[i-1] | arr[i];
    }
    suffix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        if(i % k == k - 1)
            suffix[i] = arr[i];
        else    
            suffix[i] = suffix[i+1] | arr[i];
    }
    ll result = 0;
    for(int i = k - 1; i < n; i++)
        result ^= (prefix[i] | suffix[i - k + 1]);
    cout << result << '\n';
    return 0;
}

// TC - O(n)
// SC - O(n)