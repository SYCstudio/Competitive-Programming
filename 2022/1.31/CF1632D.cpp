#include <bits/stdc++.h>
using namespace std;

#define ls(x) ((x) << 1)
#define rs(x) (((x) << 1) | 1)
const int maxN = 202000;

int n;
int A[maxN], Seg[maxN << 2];

int gcd(int a, int b);
void Build(int u, int l, int r);
int Query(int u, int l, int r, int ql, int qr);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    Build(1, 1, n);
    int lstp = 0, Ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (Query(1, 1, n, mid, i) >= i - mid + 1) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        //cout << i << " " << pos << endl;
        if (pos != -1 && Query(1, 1, n, pos, i) == i - pos + 1) {
            //cout << i << " " << Query(1, 1, n, pos, i) << endl;
            if (pos > lstp) {
                lstp = i;
                Ans++;
            }
        }
        printf("%d ", Ans);
    }
    puts("");
    return 0;
}

int gcd(int a, int b) {
    return __gcd(a, b);
}

void Build(int u, int l, int r) {
    if (l == r) {
        Seg[u] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(ls(u), l, mid);
    Build(rs(u), mid+1, r);
    Seg[u] = gcd(Seg[ls(u)], Seg[rs(u)]);
    return;
}

int Query(int u, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) return Seg[u];
    int mid = (l + r) >> 1;
    if (qr <= mid) return Query(ls(u), l, mid, ql, qr);
    else if (ql >= mid + 1) return Query(rs(u), mid+1, r, ql, qr);
    else return gcd(Query(ls(u), l, mid, ql, mid), Query(rs(u), mid+1, r, mid+1, qr));
}