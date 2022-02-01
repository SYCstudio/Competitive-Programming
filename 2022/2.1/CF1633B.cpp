#include <bits/stdc++.h>
using namespace std;

const int maxN = 202000;

int n;
string s1, s2;

bool check(int ans, string &s);

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        cin >> s1;
        n = s1.length();
        s2.resize(n);
        for (int i = 0; i < n; i++) s2[i] = s1[i] ^ 1;
        //cout << s1 << " " << s2 << endl;;
        int L = 0, R = n, Ans = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (check(mid, s1) || check(mid, s2)) L = mid + 1, Ans = mid;
            else R = mid - 1;
        }
        cout << Ans << endl;
    }
    return 0;
}

bool check(int ans, string &s) {
    for (int l = 0, r = -1, cnt = 0; l < n; l++) {
        while (r + 1 < n && (cnt < ans || s[r+1] == '1')) {
            r++;
            cnt += (s[r] == '0');
        }
        if (cnt == ans) {
            int one = (r - l + 1 - ans);
            if (one > ans) return true;
        }
        cnt -= (s[l] == '0');
    }
    return false;
}