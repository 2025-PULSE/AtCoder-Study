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

bool isfullblack(int r, int c){
    
}

void Solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H){
        cin >> S[i];
    }
    vvi G(H, vi(W, 0));
    int cnt = 0;
    rep(r, 0, H - 2){
        rep(c, 0, W - 2){
            if(S[r][c] == '#'){
                if(S[r][c] == '#' && S[r][c + 1] == '#' && S[r + 1][c] == '#' && S[r + 1][c + 1] == '#'){
                    G[r][c] += 1;
                    G[r][c + 1] += 1;
                    G[r + 1][c] += 1;
                    G[r + 1][c + 1] += 1;

                    cnt++;
                }
            }
        }
    }
    //특정 칸에 몇개가 겹치는지 개수를 알 수 있음
    //여기 있는 숫자들 갯수 세서 자연수 조합?, 수학을 못해서 못풀겠음
    rep(r, 0, H - 1){
        rep(c, 0, W - 1){
            cout << G[r][c] << sp;
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    rep(i, 1, t)
        Solve();
    return 0;
}