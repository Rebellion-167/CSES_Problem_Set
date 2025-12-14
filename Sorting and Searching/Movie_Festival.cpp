#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define pb push_back
#define nl '\n'

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr;
    for(int i = 0 ; i < n ; i++) {
        ll st, et;
        cin >> st >> et;
        arr.pb({st, et});
    }

    sort(arr.begin(), arr.end(), [](const pair<ll, ll>& p1, const 
    pair<ll, ll>& p2) {
        return p1.second < p2.second;
    });

    ll watched = 0;
    ll time = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i].first >= time) {
            watched++;
            time = arr[i].second;
        }
    }

    cout << watched << nl;
    return 0;
}

// tc - O(n log n)
// sc - O(2 * n)