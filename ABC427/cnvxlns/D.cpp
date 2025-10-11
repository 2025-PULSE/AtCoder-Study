#include <bits/stdc++.h>
using namespace std;

#define Size 200032
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)

const int MOD = 1e9 + 7;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}

pii operator-(const pii& a, const pii& b) {
    return {a.first - b.first, a.second - b.second};
}

pii dxy[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void Solve() {
    int N, M, K;
    cin >> N >> M >> K;

    vvi G(N + 1);
    string input, s;
    cin >> input;
    s = " " + input;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (1 <= u && u <= N && 1 <= v && v <= N)
            G[u].push_back(v);
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));

    for (int k = 1; k <= K; ++k) {
        for (int u = 1; u <= N; ++u) {
            bool canwin = false;
            bool aliceturn = (k % 2 == 1);
            if (k == 1) {
                
                for(auto next: G[u]){
                    if(aliceturn){
                        if(s[next] == 'A'){
                            canwin = true;
                            break;
                        }
                    }else{
                        if(s[next] == 'B') {
                            canwin = true;
                            break;
                        }
                    }
                }
            }else{
                for(int next: G[u]) {
                    if (!dp[next][k - 1]) {
                        canwin = true;
                        break;
                    }
                }
            }
            dp[u][k] = canwin;
        }
    }

    if (!dp[1][K]) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) Solve();

    return 0;
}
