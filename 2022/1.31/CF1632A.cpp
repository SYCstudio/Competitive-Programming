#include <bits/stdc++.h>
using namespace std;

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        int n;string s;
        cin >> n >> s;
        if (n >= 3) {
            cout << "NO" << endl;
            continue;
        }
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        if (n == 2) {
            if (s[0] != s[1]) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
    }
    return 0;
}