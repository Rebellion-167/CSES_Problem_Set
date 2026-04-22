#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    int k;
    cin >> k;
    vector<ll> arr(k);
    for(int i = 0; i < k; i++) cin >> arr[i];

    vector<ll> count(k+1);
    for(ll m = 1; m < (1 << k); m++) {
        ll sign = 0;
        ll temp = n;

        for(ll i = 0; i < k; i++) {
            if(m & (1 << i)) {
                temp /= arr[i];
                sign++;
            }
        }
        
        count[sign] += temp;
    }   

    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        if(i & 1) {
            ans += count[i];
        } else
            ans -= count[i];
    }
    cout << ans << '\n';
    return 0;
}

// tc - O(k * 2^k)
// sc - O(k)