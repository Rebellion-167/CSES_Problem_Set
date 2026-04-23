#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl '\n'

bool isPrime(ll n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;

    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}

void solve() {
    ll n;
    cin >> n;

    if(n < 2) {
        cout << 2 << '\n';
        return;
    }

    ll x = n + 1;
    if(x % 2 == 0) x++;
    while(true) {
        if(isPrime(x)) {
            cout << x << nl;
            return;
        }
        x += 2;
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

// tc - O(sqrt(n) * log n * t) for t test cases
// sc - O(1)