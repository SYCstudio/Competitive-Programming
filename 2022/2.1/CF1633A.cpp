#include <bits/stdc++.h>
using namespace std;

const int maxN = 1100;

int Wei[maxN];
int Ten[3];

int main() {
    int Case;
    cin >> Case;
    for (int i = 1; i <= 9; i++) Wei[i] = 1;
    for (int i = 10; i <= 99; i++) Wei[i] = 2;
    for (int i = 100; i <= 999; i++) Wei[i] = 3;
    Ten[1] = 1;
    Ten[2] = 10;
    Ten[3] = 100;
    while (Case--) {
        int Key;
        cin >> Key;
        if (Key % 7 == 0) {
            cout << Key << endl;
            continue;
        }
        int a[4] = {0, Key % 10, Key / 10 % 10, Key / 100 % 10};
        bool flag = 0;
        for (int i = 1; i <= Wei[Key]; i++) {
            int key = Key - a[i] * Ten[i];
            for (int j = 0; j <= 9; j++) {
                int _key = key + j * Ten[i];
                if (_key % 7 == 0) {
                    cout << _key << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
    }
    return 0;
}