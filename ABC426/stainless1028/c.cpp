#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pc[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    int x, y;
    int last = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        pc[i] = i;
    }
    while (q--) {
        cin >> x >> y;
        int cnt = pc[x];
        cout << cnt << "\n";
        if (cnt == 0) continue;

        for (int i = last; i <= x; i++) {
            pc[i] = 0;
        }
        last = max(last, x);
        for (int i = x + 1; i < y; i++) {
            pc[i] -= cnt;
        }
    }
    return 0;
}
