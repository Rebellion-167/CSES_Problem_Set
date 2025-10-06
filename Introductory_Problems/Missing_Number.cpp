#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    //sum of numbers upto n
    long long xor1 = 0;
    long long xor2 = 0;
    vector<long long> arr(n+1);
    for(int i = 1; i< n; i++) {
        cin >> arr[i];
        xor1 = xor1 ^ i;
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ n;
    cout << (xor1 ^ xor2);
    return 0;
}