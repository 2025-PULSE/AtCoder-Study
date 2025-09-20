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


void Solve() {
    int N, R;
    cin >> N >> R;
    vi L(N);
    for(auto &x : L) {
        cin >> x;
    }
    int ans = 0;
    int streak = 1;
    int firstone = N;
    int lastone = 0;
    for(auto i = 0; i < N; ++i){
        if(streak == 1 && L[i] == 0){
            firstone = i - 1;
            streak = 0;
        }
        if(L[i] == 0){
            streak = 0;
            ans++;
        }
    }
    for(auto i = N - 1; i >= 0; --i){
        if(L[i] == 0){
            lastone = i + 1;
            break;
        }
    }
    for(auto i = R - 1; i >= 0 && i > firstone; i--){
        if(L[i] == 1){
            ans += 2;
        }
    }
    for(auto i = R; i < N && i < lastone; i++){
        if(L[i] == 1){
            ans += 2;
        }
    }
    //cout << firstone << sp << lastone << endl;
    cout  << ans << endl;
}   

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}