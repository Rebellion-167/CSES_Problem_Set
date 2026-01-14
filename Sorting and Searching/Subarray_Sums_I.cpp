#include <iostream>
#include <vector>

#define ll long long

void solve() {
    ll n, x;
    std::cin >> n >> x;
    std::vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    ll sum = 0;
    ll i = 0, j = 0;
    ll count = 0;
    while(j < n) {
        sum += arr[j];
        while(sum > x) {
            sum -= arr[i];
            i++;
        }
        if(sum == x) count++;
        j++;
    }
    std::cout << count;
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

// time complexity - O(n)
// space complexity - O(1)