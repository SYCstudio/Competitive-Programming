#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;

int A[maxN], B[maxN];

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        for (int i = 1; i <= n; i++) cin >> B[i];
        int mn = min(A[1], B[1]), mx = max(A[1], B[1]);
        for (int i = 2; i <= n; i++) mn = max(mn, min(A[i], B[i])), mx = max(mx, max(A[i], B[i]));
        cout << mn * mx << endl;
    }
    return 0;
}