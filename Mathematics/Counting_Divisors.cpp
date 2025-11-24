#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void solve() {
    int x;
    cin >> x;
    int div = 0;
    for(int i = 1; i*i <= x; i++) {
        if(x % i == 0) {
            div++;
            if(i != (x/i))
                div++;
        }
    }
    cout << div << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}

// tc - O(n * sqrt(x))
// sc - O(1)