#include <iostream>
#include <vector>
#include <queue>
#include <ranges>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

ll fact[2020202] = {};

ll pow(ll x, ll y) {
    ll r = 1;
    while (y > 0) {
        if (y & 1) r = r * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return r;
}

ll inv(const ll x) {
    return pow(x, MOD - 2);
}

ll comb(const ll n, const ll r) {
    return fact[n] * inv(fact[r]) % MOD * inv(fact[n - r]) % MOD;
}

ll N, D, R = 1;
ll A[1010101] = {};
ll S[1010101] = {};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fact[0] = 1;
    for (ll i = 1; i < 2020202; i++) fact[i] = fact[i - 1] * i % MOD;

    cin >> N >> D;
    for (ll i = 0; i < N; i++) {
        ll v; cin >> v;
        A[v]++;
    }

    for (ll i = 0; i <= 1000000; i++) {
        S[i + 1] = S[i] + A[i];
    }

    for (ll i = 1; i <= 1000000; i++) {
        R = R * comb(A[i] + S[i] - S[max(0ll, i - D)], A[i]) % MOD;
    }

    cout << R;
}
