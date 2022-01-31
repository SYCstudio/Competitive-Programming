#include <bits/stdc++.h>
using namespace std;

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        int A, B;
        cin >> A >> B;
        int Ans = B - A;
        for (int b = B; b <= B + B + B; b++) {
            Ans = min(Ans, (A | b) - B + 1);
        }
        for (int a = A; a < B; a++) {
            Ans = min(Ans, a - A + 1 + (a | B) - B);
        }
        cout << Ans << endl;
    }
    return 0;
}