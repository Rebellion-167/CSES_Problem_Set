#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<ll, ll> mpp;
    ll cnt = 0;
    int i = 0, j = 0;
    while(j < (int)arr.size()) {
        mpp[arr[j]]++;
        while((int)mpp.size() > k) {
            mpp[arr[i]]--;
            if(mpp[arr[i]] == 0) mpp.erase(arr[i]);
            i += 1;
        }
        cnt += (j - i + 1);
        j++;
    }
    cout << cnt << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}