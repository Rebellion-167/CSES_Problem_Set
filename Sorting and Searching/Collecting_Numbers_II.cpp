#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define nl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> val(n+1);
    vector<int> pos(n+1);
    for(int i = 1 ; i <= n ; i++) {
        cin >> val[i];
        pos[val[i]] = i;
    }

    int rounds = 1;
    for(int i = 2; i <= n; i++) {
        if(pos[i-1] > pos[i]) rounds++;
    }

    auto bad = [&](int x) {
        if(x < 1 || x >= n) return false;
        return pos[x] > pos[x+1];
    };

    while(m--) {
        int a, b;
        cin >> a >> b;

        int x = val[a];
        int y = val[b];

        set<int> s = {x-1, x, y-1, y};
        for(int i : s) rounds -= bad(i);

        swap(val[a], val[b]);
        swap(pos[x], pos[y]);

        for(int i : s) rounds += bad(i);

        cout << rounds << '\n';
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n + m)
// sc - O(m)