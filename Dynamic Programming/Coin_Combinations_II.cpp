#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> prev(x+1, 0);
    for(int w = 0; w <= x; w++) prev[w] = (w % arr[0] == 0);
    for(int ind = 1; ind < n; ind++) {
        for(int w = 0; w <= x; w++) {
            int notTake = prev[w];
            int take = 0;
            if(arr[ind] <= w) take = prev[w - arr[ind]];
            prev[w] = (notTake + take) % MOD;
        }
    }
    cout << prev[x] << '\n';
    return 0;
}

// tc - O(n * x)
// sc - O(x)