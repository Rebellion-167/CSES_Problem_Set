#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> h(n);
    vector<int> t(m);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<m;i++) cin >> t[i];

    multiset<int> s;
    for(int i=0;i<n;i++) s.insert(h[i]);

    for(int i=0;i<m;i++) {
        auto it = s.upper_bound(t[i]);
        if(it == s.begin())
            cout << -1 << nl;
        else {
            --it;
            cout << *it << nl;
            s.erase(it);
        }
    }
    return 0;
}

// tc - O((n+m) log n)
// sc - O(n)