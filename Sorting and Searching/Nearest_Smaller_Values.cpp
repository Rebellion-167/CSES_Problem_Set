#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define ll long long
#define sp ' '
#define nl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n+1);
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    vector<ll> ans(n+1);
    stack<ll> st;
    for(ll i = 1; i <= n; i++) {
        while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
        ans[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    for(ll i = 1; i <= n; i++)
        cout << ans[i] << sp;
    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(N) since we are visiting all the elements of the array
// sc - O(N) since the stack can store all the indices in the worst case