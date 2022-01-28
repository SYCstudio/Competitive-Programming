#include <bits/stdc++.h>
using namespace std;

const int maxN = 200200;

int A[maxN];

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        int Ans = 0, pos = n-1;
        while (pos >= 1) {
            if (A[pos] == A[pos+1]) {
                pos--;continue;
            }
            int l = min(n - pos, pos);
            while (l--) A[pos] = A[pos+1], pos--;
            Ans++;
        }
        cout << Ans << endl;
    }
    return 0;
}