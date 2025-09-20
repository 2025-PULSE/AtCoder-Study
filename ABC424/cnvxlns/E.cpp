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
using pqi = priority_queue<int, vector<int>, greater<int>>;

pii operator+(const pii& a, const pii& b) {
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void Solve() {
    int N, K, X;
    cin >> N >> K >> X;
    priority_queue<pair<double, int>> A;
    rep(i, 1, N){
        int a;
        cin >> a;
        A.push({a, 1});
    }
    for(auto i = K; i > 0;){
        auto [topval, topcnt] = A.top();
        A.pop();
        if(i < topcnt){
            A.push({topval / 2., 2 * i});
            A.push({topval, topcnt - i});
            break;
        }
        i -= topcnt;
        A.push({topval / 2., topcnt * 2});
    }
    int rnk = 0;
    double ans;
    while(rnk < X){
        auto [topval, topcnt] = A.top();
        A.pop();
        rnk += topcnt;
        ans = topval;
    }
    cout << fixed << setprecision(9) << ans << endl;
}

int32_t main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    rep(i, 1, t)
        Solve();
    return 0;
}