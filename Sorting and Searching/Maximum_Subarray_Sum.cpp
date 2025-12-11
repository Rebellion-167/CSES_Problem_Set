#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    ll maxi = LLONG_MIN;
    ll sum = 0;

    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(sum > maxi)
            maxi = sum;
        if(sum < 0)
            sum = 0;
    }
    cout << maxi << nl;
    return 0;
}

// tc - O(n)
// sc - O(1)