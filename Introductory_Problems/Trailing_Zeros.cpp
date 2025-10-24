#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long count_5s = 0;
    while(n > 0) {
        count_5s += n / 5;
        n /= 5;
    }

    cout << count_5s << "\n";
    return 0;
}