#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times;

    for(int i=0;i<n;i++) {
        int st,et;
        cin >> st >> et;
        times.push_back({st, 1});
        times.push_back({et, -1});
    }

    sort(times.begin(), times.end());

    int curr_c = 0;
    int max_c = 0;
    for(int i=0;i<2*n;i++) {
        curr_c += times[i].second;
        max_c = max(max_c, curr_c);
    }

    cout << max_c << '\n';
    return 0;
}

// tc - O(nlogn)
// sc - O(n) for labels