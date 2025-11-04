#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

bool is_safe(vector<string>& board, int r, int c) {
    if(board[r][c] == '*') return false;

    int i = r - 1, j = c - 1;
    while(i >= 0 and j >= 0) {
        if(board[i][j] == 'Q') return false;
        i--, j--;
    }

    j = c - 1;
    while(j >= 0) {
        if(board[r][j] == 'Q') return false;
        j--;
    }

    i = r + 1, j = c - 1;
    while(i < 8 and c >= 0) {
        if(board[i][j] == 'Q') return false;
        i++, j--;
    }

    return true;
}

void count_placements(vector<string>& board, int& ans, int c) {
    if(c == 8) {
        ans++;
        return;
    }

    for(int r = 0; r < 8; r++) {
        if(is_safe(board, r, c)) {
            board[r][c] = 'Q';
            count_placements(board, ans, c+1);
            board[r][c] = '.';
        }
    }
}

void solve() {
    vector<string> board(8);
    for(int i=0;i<8;i++)
        cin >> board[i];

    int ans = 0;
    int col = 0;
    count_placements(board, ans, col);

    cout << ans << nl;
    return;
}

int main() {
    solve();
    return 0;
}

// tc - O(n * (n^n))
// sc - O(n*n + n)