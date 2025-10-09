#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    long long i = 1, j = 2;
    vector<long long> v;
    while(j <= n) {
        v.push_back(j);
        j += 2;
    }
    while(i <= n) {
        v.push_back(i);
        i += 2;
    }

    if(n <= 3 && n!= 1)
        cout << "NO SOLUTION" << endl;
    else if(n == 1) cout << 1 << endl;
    else {
        for(long long i = 0; i < n; i++) 
            cout << v[i] << " ";
        cout << endl;
    } 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    solve(n);
    return 0;
}