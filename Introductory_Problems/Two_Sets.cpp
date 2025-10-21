#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f;
    vector<int> s;

    if((n * (n + 1) / 2) % 2 != 0)
        cout << "NO" << endl;
    else {
        if(n % 2 == 0) {
            for(int i=0;i<n/2;i++) {
                if(i % 2 == 0) {
                    f.push_back(i + 1);
                    f.push_back(n - i);
                } else {
                    s.push_back(i + 1);
                    s.push_back(n - i);
                }
            }
        } else {
            for(int i=0;i<(n - 1)/2;i++) {
                if(i % 2 == 0) {
                    f.push_back(i + 1);
                    f.push_back(n - i -1);
                } else {
                    s.push_back(i + 1);
                    s.push_back(n - i - 1);
                }
            }

            if(f.size() > s.size())
                s.push_back(n);
            else
                f.push_back(n);
        }
        cout << "YES" << endl;
        cout << f.size() << endl;
        for(size_t i=0;i<f.size();i++) {
            cout << f[i] << " ";
        }
        cout << "\n";
    
        cout << s.size() << endl;
        for(size_t i=0;i<s.size();i++) {
            cout << s[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}