#include <bits/stdc++.h>
using namespace std;

const int maxN = 202000;

int A[maxN];

int highbit(int x) {
    int b = 1;
    x >>= 1;
    while (x) {
        x >>= 1;
        b <<= 1;
    };
    return b;
}

int main() {
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) A[i] = 0;
        int high = highbit(n-1);
        vector<int> Ans;
        int lst = 0;
        for (int i = n-1; i >= 0; i--)
            if (A[i] == 0 && (i & high) != 0) {
                A[i] = 1;lst = i;Ans.push_back(i);
            }
        A[lst ^ high] = 1;
        Ans.push_back(lst ^ high);
        for (int i = 0; i < n; i++)
            if (A[i] == 0) Ans.push_back(i);
        
        for (auto key:Ans) printf("%d ", key);
        printf("\n");
        /*
        int mx = 0;
        for (int i = 0; i < n-1; i++)
            mx = max(mx, Ans[i] ^ Ans[i+1]);
        cout << mx << endl;
        //*/
    }
    return 0;
}