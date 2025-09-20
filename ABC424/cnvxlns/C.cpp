#include<bits/stdc++.h>

#define Size 200032
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

const int MOD = 1e9 + 7;

using namespace std;

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
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

vvi G;
vi visited;

int dfs(int idx){
    //cout << idx << endl;
    if(visited[idx]){
        return 0;
    }
    visited[idx] = 1;
    int ret = 1;
    for(const auto &to : G[idx]){
        ret += dfs(to);
    }
    return ret;
}


void Solve() {
    int N;
    cin >> N;
    G.resize(N + 1);
    visited.assign(N + 1, 0);
    vi start;
    rep(i, 1, N){
        int x, y;
        cin >> x >> y;
        if(x == 0){
            start.push_back(i);
        }else{
            G[x].push_back(i);
            G[y].push_back(i);
        }
    }
    int ans = 0;
    for(const auto &s : start){
        ans += dfs(s);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}