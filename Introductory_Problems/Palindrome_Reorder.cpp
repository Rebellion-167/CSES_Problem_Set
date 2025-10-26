#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    unordered_map<char, int> mpp;
    for(char ch: s) 
        mpp[ch]++;

    char center = '\0';
    int oddCount = 0;
    for(const auto &it : mpp) {
        char ch = it.first;
        int count = it.second;
        if(count % 2 == 1) {
            oddCount++;
            center = ch;
            if(oddCount > 1) {
                cout << "NO SOLUTION\n";
                return;
            }
        }
    }

    string result;
    result.reserve(s.length());

    for(const auto& it : mpp) {
        char ch = it.first;
        int count = it.second;
        result.append(count/2 , ch);
    }

    if(center != '\0')
        result += center;

    int firstHalfSize = s.length() / 2;

    for(int i = firstHalfSize - 1; i >= 0; i--)
        result.push_back(result[i]);

    cout << result << "\n";
    return;
}

int main() {
    solve();
    return 0;
}