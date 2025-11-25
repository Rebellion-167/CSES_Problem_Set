#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define len(x) (int)((x).size())

bool is_possible(vector<int>& freq, char ch) {
    char mode = ch;
    int f = freq[ch - 'A'];
    int filled = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > f) {
            mode = 'A' + i;
            f = freq[i];
        }
        filled += freq[i];
    }

    return (freq[mode - 'A'] <= (filled + 1) / 2) and (freq[ch - 'A'] <= filled / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = len(s);

    vector<int> freq(26);
    for(int i = 0; i < n; i++) 
        freq[s[i] - 'A']++;
    
    string ans = "";
    char last = '\0';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) {
            char ch = 'A' + j;

            if(freq[ch - 'A'] == 0 || ch == last) continue;
            
            freq[ch - 'A']--;
            if(is_possible(freq, ch)) {
                ans.push_back(ch);
                last = ch;
                break;
            } else {
                freq[ch - 'A']++;
            }
        }
    }

    if(len(ans) == n)
        cout << ans << nl;
    else
        cout << -1 << nl;
    return 0;
}