#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define ll long long
#define sp ' '
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    set<ll> unseen;
    map<ll, ll> mpp;
    for(ll i = 0; i <= k; i++) unseen.insert(i);
    for(ll i = 0; i < k; i++) {
        mpp[arr[i]]++;
        unseen.erase(arr[i]);
    }
    for(ll i = k; i <= n; i++) {
        cout << *unseen.begin() << sp;
        mpp[arr[i-k]]--;
        if(mpp[arr[i-k]] == 0) unseen.insert(arr[i-k]);
        mpp[arr[i]]++;
        unseen.erase(arr[i]);
    }
    return 0;
}
// tc - O(n log k)
// sc - O(k)