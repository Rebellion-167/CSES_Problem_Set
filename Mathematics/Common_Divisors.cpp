#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define N 1e6

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> freq(N);
    for(int i=0; i<n; i++) freq[arr[i]]++;

    for(int i=N; i>=0; i--) {
        int d = 0;
        for(int j = i; j <= N; j += i) d += freq[j];
        if(d >= 2) {
            cout << i << nl;
            return 0;
        }
    }
}

// tc - O(N * log N)
// sc - O(N)