#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i = 1 ; i <= n ; i++) {
        int temp;
        cin >> temp;
        arr.push_back({temp, i});
    }

    sort(arr.begin(), arr.end());

    int rounds = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i+1].second < arr[i].second)
            rounds++;
    }

    cout << rounds << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(nlogn)
// sc - O(2n)