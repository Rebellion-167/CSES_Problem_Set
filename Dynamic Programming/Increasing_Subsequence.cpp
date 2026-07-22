#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        } else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    cout << len << endl;
    return 0;
}

// tc - O(n log n)
// sc - O(n)