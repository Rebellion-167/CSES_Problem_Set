#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    if (s.empty()) { 
        cout << 0 << endl;
        return;
    }

    int max_len = 1;
    int curr_len = 1;
    char current = s[0];

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == current) {
            curr_len++;
        } else {
            current = s[i];
            curr_len = 1;
        }
        max_len = max(max_len, curr_len);
    }

    cout << max_len << endl;
}

int main() {
    string s;
    cin >> s;
    solve(s);
    return 0;
}
