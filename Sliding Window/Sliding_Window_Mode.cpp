#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define sp ' '
#define nl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    map<ll, ll> mpp;
    multiset<pair<ll, ll>> st;
    for(ll i = 0; i < k; i++) {
        if(mpp[arr[i]] > 0)
            st.erase(st.find({mpp[arr[i]], -arr[i]}));
        mpp[arr[i]]++;
        st.insert({mpp[arr[i]], -arr[i]}); 
    }
    for(ll i = k; i < n; i++) {
        auto it = prev(st.end());
        cout << abs(it->second) << sp;
        st.erase(st.find({mpp[arr[i-k]], -arr[i-k]}));
        mpp[arr[i-k]]--;
        if(mpp[arr[i-k]] > 0)
            st.insert({mpp[arr[i-k]], -arr[i-k]});
        if(mpp[arr[i]] > 0)
            st.erase(st.find({mpp[arr[i]], -arr[i]}));
        mpp[arr[i]]++;
        st.insert({mpp[arr[i]], -arr[i]});
    }
    auto it = prev(st.end());
    cout << abs(it->second) << sp;
    cout << nl;
    return 0;
}
// tc - O(n log n)
// sc - O(n)