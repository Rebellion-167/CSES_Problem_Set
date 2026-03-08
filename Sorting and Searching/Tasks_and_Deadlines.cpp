#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define nl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> tasks(n);
    for(int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;

    sort(tasks.begin(), tasks.end());

    ll tot_reward;
    ll curr_reward = 0;
    ll time = 0;
    for(int i = 0; i < n; i++) {
        time += tasks[i].first;
        tot_reward = tasks[i].second - time;
        curr_reward += tot_reward;
    }
    cout << curr_reward << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n log n)
// sc - O(n)