#include <bits/stdc++.h>
using namespace std;

const int maxN = 202000;
const int inf = 2000000000;

int A[maxN], B[maxN];

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        int n, K;
        cin >> n >> K;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        sort(&B[1], &B[n+1]);
        int ansl, ansr, ansgap = inf;
        for (int i = 1, gap = (n + K + 1) / 2; i + gap - 1 <= n; i++)
            if (B[i + gap - 1] - B[i] < ansgap) {
                ansgap = B[i + gap - 1] - B[i];
                ansl = B[i]; ansr = B[i + gap - 1];
            }
        cout << ansl << " " << ansr << endl;
        for (int i = 1, lastl = 0, sum = 0, cnt = 0; i <= n; i++) {
            if (A[i] >= ansl && A[i] <= ansr) sum++;
            else sum--;
            if (i == n || (sum > 0 && cnt < K - 1)) {
                cout << lastl + 1 << " " << i << endl;
                lastl = i;
                sum = 0;
                cnt++;
            }
        }
    }
    return 0;
}