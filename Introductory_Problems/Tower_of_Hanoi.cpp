#include <bits/stdc++.h>

using namespace std;

void TH(int discs, int start, int end, int aux) {
    // Base case : If there is only 1 disc
    if(discs == 1) {
        cout << start << " " << end << "\n";
        return;
    }    
    // Moving discs from 1 to 2 using 3
    TH(discs - 1, start, aux, end);
    // Moving the largest disc to 3
    cout << start << " " << end << "\n";
    // Moving discs from 2 to 3 using 1
    TH(discs - 1, aux, end, start);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    TH(n, 1, 3, 2);
    return 0;
}

// tc - O(2^n)
// sc - O(n)