#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ranges>
using namespace std;
using ll = long long;

ll X, N, Q;
ll A[101] = {};
ll B[101] = {};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> X >> N;
    for (ll i = 1; i <= N; i++) cin >> A[i];

    cin >> Q;
    while (Q--) {
        ll i;
        cin >> i;
        B[i] ^= 1;

        ll res = X;
        for (ll i = 1; i <= N; i++) {
            res += A[i] * B[i];
        }

        cout << res << "\n";
    }
}
