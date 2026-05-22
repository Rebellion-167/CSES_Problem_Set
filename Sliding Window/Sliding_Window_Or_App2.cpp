#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define nl '\n'
ll OR (ll a, ll b) {
    return a | b;
}
template <class T, T (*F)(T, T)>
struct AggStack {
    stack<pair<T, T>> st;
    void push(T x) {
        ll curr = st.empty() ? x : F(st.top().second, x);
        st.push({x, curr});
    }
    T pop() {
        ll curr = st.top().first;
        st.pop();
        return curr;
    }
    bool empty() {
        return st.empty();
    }
    T agg() {
        return st.top().second;
    }
};
template <class T, T (*F)(T, T)>
struct AggQueue {
    AggStack<T, F> in, out;
    void push(T val) {
        in.push(val);
    }
    T pop() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }
    T get() {
        if(in.empty()) return out.agg();
        if(out.empty()) return in.agg();
        return F(in.agg(), out.agg());
    }
};
      
void solve() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n);
    arr[0] = x;
    for(ll i = 1; i < n; i++) {
        arr[i] = (a * arr[i-1] + b) % c;
    }
    AggQueue<ll, OR> Q;

    ll ans = 0;
    ll i = 0;
    for(ll j = 0; j < n; j++) {
        Q.push(arr[j]);
        if(j - i + 1 < k) continue;
        ans = ans xor Q.get();
        Q.pop();
        i++; 
    }
    cout << ans << nl;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// TC - O(n)
// SC - O(n)