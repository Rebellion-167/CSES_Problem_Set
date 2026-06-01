#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define sp ' '
#define nl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    multiset<ll> left, right;
    ll ls = 0, rs = 0;
    auto rebalance = [&] {
        if(left.size() > right.size()) {
            ll v = *rbegin(left);
            ls -= v;
            rs += v;
            left.erase(left.find(v));
            right.insert(v);
        }
        if(right.size() > left.size() + 1) {
            ll v = *begin(right);
            rs -= v;
            ls += v;
            right.erase(right.find(v));
            left.insert(v);
        }
    };
    auto add = [&](ll v) {
        if(!right.empty() and v >= *begin(right)) {
            rs += v;
            right.insert(v);
        } else {
            ls += v;
            left.insert(v);
        }
        rebalance();
    };
    auto rem = [&](ll v) {
        if(v >= *begin(right)) {
            rs -= v;
            right.erase(right.find(v));
        } else {
            ls -= v;
            left.erase(left.find(v));
        }
        rebalance();
    };
    auto cost = [&] {
        ll med = *begin(right);
        return left.size() * med - ls + rs - right.size() * med;
    };
    ll i = 0;
    for(ll j = 0; j < n; j++) {
        add(arr[j]);
        if(j - i + 1 < k) continue;
        cout << cost() << ' ';
        rem(arr[i]);
        i++;
    }   
    return 0;
}
// tc - O(n log k)
// sc - O(k)