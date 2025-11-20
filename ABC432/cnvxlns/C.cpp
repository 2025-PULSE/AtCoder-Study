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
    int N, X, Y;
    cin >> N >> X >> Y;
    auto d = Y - X;
    vi A(N);
    for(auto &i: A){
        cin >> i;
    }

    int r = ((A[0] * X) % d + d) % d;
    int m = A[0] * X;
    int M = A[0] * Y;

    for(int i = 1; i < N; ++i) {
        auto newr = ((A[i] * X) % d + d) % d;
        if (newr != r) {
            cout << -1 << endl;
            return;
        }
        
        m = max(A[i] * X, m);
        M = min(A[i] * Y, M);

        if (m > M) {
            cout << -1 << endl;
            return;
        }
    }
    int ans = 0;
    for(auto i: A){
        ans += (M - i * X) / d;
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie()->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}