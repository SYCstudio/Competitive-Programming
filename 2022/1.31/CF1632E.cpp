#include <bits/stdc++.h>
using namespace std;

const int maxN = 303000;

int n;
vector<int> E[maxN];
int Dst[maxN], Mxd[maxN], Depth[maxN];

void dfs(int u, int fa);

int main() {
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            E[i].clear();
            Dst[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            E[u].push_back(v);E[v].push_back(u);
        }
        Depth[1] = 0;
        dfs(1, 0);
        int mxans = Mxd[1];
        for (int i = n-1; i >= 0; i--) Dst[i] = max(Dst[i], Dst[i+1]);
        for (int i = 1, ans = 0; i <= n; i++) {
            while (ans < mxans && Dst[ans] / 2 + i > ans) ans++;
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}

void dfs(int u, int fa) {
    int mx1 = Depth[u], mx2 = Depth[u];
    for (auto v:E[u]) {
        if (v == fa) continue;
        Depth[v] = Depth[u] + 1;
        dfs(v, u);
        if (Mxd[v] >= mx1) mx2 = mx1, mx1 = Mxd[v];
        else if (Mxd[v] > mx2) mx2 = Mxd[v];
    }
    if (mx2 > 0) Dst[mx2-1] = max(Dst[mx2-1], mx1 + mx2 - Depth[u] - Depth[u] + 1);
    Mxd[u] = mx1;
    return;
}