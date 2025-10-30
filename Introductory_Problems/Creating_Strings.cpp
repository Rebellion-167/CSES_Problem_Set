#include <bits/stdc++.h>

using namespace std;

#define len(x) int((x).size())
#define nl '\n'

int fact(int n) {
    int res = 1;
    for(int i = 1; i<= n; i++) res *= i;
    return res;
}

void print_permutations(map<char, int>& mpp, string& aux, int n) {
    // Base case
    if(len(aux) == n) {
        cout << aux << nl;
        return;
    }

    for(int i=0; i<26; i++) {
        char ch = 'a' + i;
        if(mpp.find(ch) != mpp.end()) {
            aux.push_back(ch);
            if(mpp[ch] == 1)
                mpp.erase(ch);
            else
                mpp[ch]--;

            print_permutations(mpp, aux, n);

            mpp[ch]++;
            aux.pop_back();
        }
    }
}

void solve() {
    string s;
    cin >> s;

    int n = len(s);

    map<char, int> mpp;
    for(auto ch : s)
        mpp[ch]++;

    int divisor = 1;
    for(auto& it : mpp) {
        int f = it.second;
        divisor *= fact(f);
    }
    cout << (fact(n) / divisor) << nl;

    string aux = "";
    print_permutations(mpp, aux, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

// tc - O(n!)
// sc - O(n)