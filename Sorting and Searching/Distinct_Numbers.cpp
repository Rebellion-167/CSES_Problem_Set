#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i=0;i<n;i++) std::cin >> arr[i];

    std::map<int, int> mpp;
    for(int i=0;i<n;i++)    mpp[arr[i]]++;

    std::cout << mpp.size() << std::endl;

    return 0;
}