#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ' '
#define nl '\n'

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<ll, int>> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end());


    int i = 0, j = n - 1;
    int flag = 0;
    while(i < j) {
        if(arr[i].first + arr[j].first == x) {
            flag = 1;
            break;
        } else if(arr[i].first + arr[j].first < x) {
            i++;
        } else {
            j--;
        }
    }

    if(flag) {
        cout << arr[i].second << sp << arr[j].second << nl;
    } else {
        cout << "IMPOSSIBLE" << nl;
    }
    return 0;
}

// tc - O(n log n)
// sc - O(2*n)