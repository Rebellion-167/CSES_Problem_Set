#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define nl '\n'
#define sp ' '
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    map<ll, ll> mpp;
    for(ll i = 0; i < k; i++) mpp[arr[i]]++;
    for(ll i = k; i < n; i++) {
        cout << mpp.size() << sp;
        mpp[arr[i]]++;
        mpp[arr[i-k]]--;
        if(mpp[arr[i-k]] == 0) mpp.erase(arr[i-k]);
    }
    cout << mpp.size();
    cout << nl;
    return 0;
}
// tc - O(n log n)
// sc - O(n)