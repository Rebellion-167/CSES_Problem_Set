#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define nl '\n'
#define sp ' '

void solve() {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<pair<ll, int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(i > 0 and arr[i].first == arr[i-1].first) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            ll sum = arr[i].first + arr[j].first + arr[k].first;
            if(sum < x) {
                j++;
            } else if(sum > x) {
                k--;
            } else {
                vector<int> temp = {arr[i].second, arr[j].second, arr[k].second};
                ans.push_back(temp);
                flag = true;
            }
            if(flag) break;
        }
    }

    if(ans.empty()) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    for(vector<int> temp : ans) {
        for(int x : temp) {
            cout << x << sp;
        }
        cout << nl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(N log N) + O(N^2)
// sc - O(no. of unique triplets)