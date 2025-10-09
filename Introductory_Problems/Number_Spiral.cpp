#include <bits/stdc++.h>
using namespace std;

void solve(long x, long y) {
    // x row, y col
    long long maxi = max(x, y);
    long long diag = (maxi * maxi) - (maxi - 1);
    long long num;
    if(x > y) {
        if(maxi % 2 == 0)
            num = diag + (x - y);
        else   
            num = diag - (x - y);
    } else {
        if(maxi % 2 == 0)
            num = diag - (y - x);
        else
            num = diag + (y - x);
    }
    cout << num << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

    while(t--) {
        long long x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}