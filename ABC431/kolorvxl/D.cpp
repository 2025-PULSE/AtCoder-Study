#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ranges>
using namespace std;
using ll = long long;

struct part {
    ll weight;
    ll value;
};

vector<part> A;

ll N, W, X = 0;
ll DP[150000] = {};

ll H, B;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    while (N--) {
        ll w, h, b;
        cin >> w >> h >> b;
        W += w;
        X += b;
        A.push_back({w, h - b});
    }

    W /= 2;
    for (const auto [w, v] : A) {
        for (ll i = W; i >= w; i--) {
            DP[i] = max(DP[i], DP[i - w] + v);
        }
    }

    cout << DP[W] + X;
}
