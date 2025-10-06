#include <bits/stdc++.h>
using namespace std;

void solve(long long n, vector<long long>& arr) {
    long long ops = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            ops += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    cout << ops << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    solve(n, arr);
    return 0;
}