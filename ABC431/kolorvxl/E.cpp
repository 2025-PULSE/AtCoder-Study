#include <iostream>
#include <vector>
#include <queue>
#include <ranges>
using namespace std;
using ll = long long;

struct pos {
    ll i, j, k, w;

    bool operator<(const pos &o) const {
        return w > o.w;
    }
};

ll H, W;
vector<string> F;

ll V[202020][4] = {};
priority_queue<pos> Q;

ll map[3][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {3, 2, 1, 0}
};

ll solve() {
    cin >> H >> W;
    F.resize(H);
    for (auto &f: F) cin >> f;

    for (ll i = 0; i < H * W; i++) {
        for (ll j = 0; j < 4; j++) {
            V[i][j] = -1;
        }
    }

    Q.push({0, 0, 0});
    while (!Q.empty()) {
        auto [i, j, k, w] = Q.top();
        Q.pop();
        if (i < 0 || i >= H || j < 0 || j >= W) continue;
        const ll x = i * W + j, y = k;
        if (V[x][y] != -1) continue;
        V[x][y] = w;

        //cout << i << " " << j << " " << k << " " << w << "\n";

        Q.push({i, j + 1, 0, w + 1});
        Q.push({i + 1, j, 1, w + 1});
        Q.push({i, j - 1, 2, w + 1});
        Q.push({i - 1, j, 3, w + 1});

        const ll d = map[F[i][j] - 'A'][k];
        if (d == 0) {
            Q.push({i, j + 1, 0, w});
        }
        if (d == 1) {
            Q.push({i + 1, j, 1, w});
        }
        if (d == 2) {
            Q.push({i, j - 1, 2, w});
        }
        if (d == 3) {
            Q.push({i - 1, j, 3, w});
        }
    }

    for (ll i = 0; i < H * W; i++) {
        for (ll j = 0; j < 4; j++) {
            if (V[i][j] == -1) {
                V[i][j] = 998244353;
            }
        }
    }

    if (F[H - 1][W - 1] == 'A') {
        return min(V[H * W - 1][0], V[H * W - 1][1] + 1);
    }

    if (F[H - 1][W - 1] == 'B') {
        return min(V[H * W - 1][0] + 1, V[H * W - 1][1]);
    }

    return min(V[H * W - 1][0] + 1, V[H * W - 1][1] + 1);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}
