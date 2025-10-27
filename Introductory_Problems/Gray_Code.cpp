#include <bits/stdc++.h>

using namespace std;

vector<string> generate_gc(int n) {
    // Base Case : If n is 1
    if(n == 1) return {"0", "1"};

    // Finding the gray code of n - 1
    vector<string> gc_n_minus_1 = generate_gc(n - 1);
    // Reversing
    vector<string> mirrored = gc_n_minus_1;
    reverse(mirrored.begin(), mirrored.end());

    // Creating gray codes with 'n' bits
    vector<string> new_codes;
    for(int i=0; i < gc_n_minus_1.size(); i++) 
        new_codes.push_back("0" + gc_n_minus_1[i]);
    for(int i=0; i < mirrored.size(); i++)
        new_codes.push_back("1" + mirrored[i]);

    return new_codes;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = generate_gc(n);
    for(const auto& it: ans) {
        cout << it << "\n";
    }
    return 0;
}

// tc - O(n * 2^n)
// sc - O(2^n + n)