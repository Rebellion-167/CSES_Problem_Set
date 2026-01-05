#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'
#define sp ' '

void josephus_series(vector<int>& arr, vector<int>& temp) {
    int n = arr.size();

    if(n == 1) {
        temp.push_back(arr[0]);
        return;
    }

    if(n == 2) {
        temp.push_back(arr[1]);
        temp.push_back(arr[0]);
        return;
    }

    for(int i = 1; i < n; i += 2) 
        if(i & 1)
            temp.push_back(arr[i]);

    vector<int> t;
    if(!(n & 1)) {
        for(int i = 0; i < n; i += 2)
            t.push_back(arr[i]);
    } else {
        t.push_back(arr[n - 1]);
        for(int i = 0; i < n - 2; i += 2)
            t.push_back(arr[i]);
    }

    josephus_series(t, temp);
    return;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = i+1;

    vector<int> temp;
    josephus_series(arr, temp);

    for(int x : temp)
        cout << x << sp;
    cout << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// tc - O(N)
// sc - O(N) for recursion stack