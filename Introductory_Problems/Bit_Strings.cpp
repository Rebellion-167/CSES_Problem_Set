#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long binpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while(b > 0) {
        if(b & 1) 
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    long long ans = binpow(2, n);
    cout << ans << endl;

    return 0;
}