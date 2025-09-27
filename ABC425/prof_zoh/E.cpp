#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
ll T, M;
ll comb[5001][2501];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T >> M;
    for (int i = 0; i <= 5000; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= min(i, 2500); j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
        }
    }

    while (T--){
        int n; cin >> n;
        vector<ll> C(n);
        for (int i = 0; i < n; i++) cin >> C[i];
        ll su = accumulate(C.begin(), C.end(), 0);
        ll ans = 1;
        for (int i = 0; i < n; i++){
            ans = (ans * comb[su][min(C[i], su - C[i])]) % M;
            su -= C[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
