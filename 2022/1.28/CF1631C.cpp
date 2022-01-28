#include <bits/stdc++.h>
using namespace std;

#define f(x) ((x) ^ (n-1))

const int maxN = (1 << 16) + 10;

pair<int, int> Out[maxN];

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        int n, K;
        cin >> n >> K;
        if (K == 0) {
            for (int i = 0, scnt = 0; i < n; i++)
                if (i < f(i)) Out[scnt++] = make_pair(i, f(i));
        }
        else if (K < n-1) {
            Out[0] = make_pair(0, f(K));
            Out[1] = make_pair(K, n-1);
            for (int i = 1, scnt = 2; i < n-1; i++)
                if (i < f(i) && i != K && i != f(K)) Out[scnt++] = make_pair(i, f(i));
        }
        else {
            if (n == 4) {
                cout << -1 << endl;
                continue;
            }
            Out[0] = make_pair(n-2, n-1);
            Out[1] = make_pair(n-3, 1);
            Out[2] = make_pair(0, 2);
            for (int i = 3, scnt = 3; i < n-3; i++)
                if (i < f(i)) Out[scnt++] = make_pair(i, f(i));
        }
        for (int i = 0; i + i < n; i++)
            cout << Out[i].first << " " << Out[i].second << endl;
    }
    return 0;
}