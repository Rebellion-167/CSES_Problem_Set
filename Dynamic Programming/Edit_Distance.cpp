#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for(int j = 0; j <= m; j++) prev[j] = j;
    for(int i = 1; i <= n; i++) {
        curr[0] = i;
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) curr[j] = prev[j-1];
            else {
                int insert = curr[j-1];
                int _delete = prev[j];
                int replace = prev[j-1];
                curr[j] = 1 + min(insert, min(_delete, replace));
            }
        }
        prev = curr;
    }
    int ans = prev[m];
    cout << ans << '\n';
    return 0;
}

// tc - O(n * m)
// sc - O(m)