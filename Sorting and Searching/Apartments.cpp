#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)    cin >> a[i];
    vector<int> b(m);
    for(int i=0;i<m;i++)    cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int cnt = 0;
    int i,j;
    for(i=0,j=0;i<n && j<m;) {
        if((a[i] >= b[j] - k) && (a[i] <= b[j] + k)) {
            cnt++, i++, j++;
        }
        else if(a[i] < b[j])    i++;
        else j++;
    }

    cout << cnt << "\n";
    return 0;
}