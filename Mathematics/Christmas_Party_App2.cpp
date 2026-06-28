#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<long long> ans(n+1);
    ans[1] = 0;
    for(int i = 2; i <= n; i++) {
        ans[i] = (i * ans[i - 1] + (i % 2 ? -1 : 1)) % mod;
    }
    cout << ans[n] << '\n';
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(n)
// sc - O(n)