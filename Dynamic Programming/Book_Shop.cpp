#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<int> prev(x+1, 0);
    for(int w = 0; w <= x; w++) {
        if(h[0] <= w) prev[w] = s[0]; 
    }
    for(int ind = 1; ind < n; ind++) {
        for(int w = x; w >= 0; w--) {
            int notTake = prev[w];
            int take = INT_MIN;
            if(h[ind] <= w) take = s[ind] + prev[w-h[ind]];
            prev[w] = max(take, notTake);
        }
    }
    int ans = prev[x];
    cout << ans << '\n';
    return 0;
}

// tc - O(n * x)
// sc - O(x)