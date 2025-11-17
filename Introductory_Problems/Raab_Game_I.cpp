#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

void rotateArray(vector<int>& arr, int b, int tie) {
    if(b == 0)
        return;

    int n = arr.size();
    if(n == 0) return;

    int temp = arr[n - 1 - tie];
    for(int i = n - 1 - tie; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    rotateArray(arr, --b, tie);
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a+b > n) {
        cout << "NO" << nl;
        return;
    } 
    if((a == 0 || b == 0) and (a + b != 0)) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    vector<int> arr(n);
    for(int i = 1; i <= n; i++) { // n
        cout << i << ' ';
        arr[i-1] = i;
    }
    cout << nl;
    int tie = n - a - b;
    rotateArray(arr, b, tie); // n * b
    for(auto it : arr) // n
        cout << it << ' ';
    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}

// tc - O(n * b) for each test case
// sc - O(n)