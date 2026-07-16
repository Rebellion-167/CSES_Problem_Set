#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> prev(totSum+1, false), curr(totSum+1, false);
    prev[0] = curr[0] = true;
    if(arr[0] <= totSum) prev[arr[0]] = true;
    for(int i = 1; i < n; i++) {
        for(int s = 1; s <= totSum; s++) {
            bool notPick = prev[s];
            bool pick = false;
            if(arr[i] <= s) pick = prev[s - arr[i]];
            curr[s] = notPick or pick;
        }
        prev = curr;
    }
    vector<int> ans;
    for(int s = 1; s <= totSum; s++) {
        if(prev[s]) ans.push_back(s);
    }
    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// tc - O(n * totSum)
// sc - O(totSum)