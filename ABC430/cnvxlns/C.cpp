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
    int N, A, B;
    cin >> N >> A >> B;
    string s;
    cin >> s;
    vi a(N + 1, 0), b(N + 1, 0);

    for(auto i = 0; i < N; ++i){
        if(s[i] == 'a'){
            a[i + 1] = a[i] + 1;
            b[i + 1] = b[i];
        }else{
            a[i + 1] = a[i];
            b[i + 1] = b[i] + 1;
        }
    }
    int hi = 1;
    int hi_margin = 1;
    int ans = 0;
    const int zero = 0;
    for(int lo = 1; lo <= N; ++lo){
        hi = max(hi, lo);
        hi_margin = max(hi_margin, lo);

        while(hi <= N && a[hi] - a[lo - 1] < A){
            hi++;
        }
        while(hi_margin <= N && b[hi_margin] - b[lo - 1] < B){
            hi_margin ++;
        }
        if(hi > N){
            break;
        }
        ans += max(zero, hi_margin - hi);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}