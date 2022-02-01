#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;
const int maxK = 1010000;
const int inf = 2000000000;

int n, K;
int B[maxN], C[maxN], F[maxN], S[maxN];
int Dp[maxK];

int main() {
    F[0] = inf;
    F[1] = 0;
    for (int i = 2; i < maxN; i++) F[i] = inf;
    for (int i = 1; i < maxN; i++)
        for (int j = 1; j <= i; j++)
            if (i + i/j < maxN) {
                int k = i + i / j;
                F[k] = min(F[k], F[i] + 1);
            }
    //int mxf = 0;
    //for (int i = 1; i < maxN; i++) mxf = max(mxf, F[i]);
    //cout << "mxf:" << mxf << endl;
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d%d", &n, &K);
        int sums = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
            S[i] = F[B[i]];
            sums += S[i];
        }
        for (int i = 1; i <= n; i++) scanf("%d", &C[i]);
        for (int i = 0; i <= sums; i++) Dp[i] = 0;
        for (int i = 1, sum = 0; i <= n; i++) {
            for (int j = sum; j >= 0; j--) 
                if (j + S[i] <= K)
                    Dp[j+S[i]] = max(Dp[j+S[i]], Dp[j] + C[i]);
            sum = min(K, sum + S[i]);
        }
        int Ans = 0;
        for (int i = 0; i <= sums; i++) Ans = max(Ans, Dp[i]);
        printf("%d\n", Ans);
    }
    return 0;
}