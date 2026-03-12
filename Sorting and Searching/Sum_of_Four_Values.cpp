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
    int i;
    for(i = 0; i < n; i++) {
        if(i != 0 and arr[i].first == arr[i-1].first) continue;
        for(int j = i+1; j < n; j++) {
            if(j != i+1 and arr[j].first == arr[j-1].first) continue;
            int k = j+1;
            int l = n-1;
            while(k < l) {
                ll sum = arr[i].first + arr[j].first;
                sum += arr[k].first;
                sum += arr[l].first;
                if(sum == x) {
                    cout << arr[i].second << sp;
                    cout << arr[j].second << sp;
                    cout << arr[k].second << sp;
                    cout << arr[l].second << sp;
                    return;
                } else if(sum < x) k++;
                else l--;
            }
        }
    }

    if(i == n) cout << "IMPOSSIBLE" << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n^3)
// sc - O(1)