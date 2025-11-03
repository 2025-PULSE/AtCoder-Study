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
    int N;
    cin >> N;
    set<int> pos;
    map<int, int> dist;
    int ans = 0;
    pos.insert(0);

    int x;
    cin >> x;
    pos.insert(x);
    dist[0] = dist[x] = x;
    ans += 2 * x;
    cout << ans << endl;

    for(auto i = 1; i < N; ++i){
        cin >> x;
        auto iterL = pos.end();
        auto iterR = pos.lower_bound(x);
        
        if(iterR != pos.begin()){
            iterL = prev(iterR);
        }

        int distL, distR;
        distL = distR = inf;


        if(iterL != pos.end()){
            distL = x - *iterL;
        }
        if(iterR != pos.end()){
            distR = *iterR - x;
        }



        int d = min(distL, distR);
        ans += d;

        if (iterL != pos.end()) {
            auto Y_L = *iterL;
            auto distL_old = dist[Y_L];
            auto distL_new = min(distL_old, distL);

            ans += (distL_new - distL_old);
            dist[Y_L] = distL_new;
        }
        if (iterR != pos.end()) {
            auto Y_R = *iterR;
            auto distR_old = dist[Y_R];
            auto distR_new = min(distR_old, distR);

            ans += (distR_new - distR_old);
            dist[Y_R] = distR_new;
        }
        pos.insert(x);
        dist[x] = d;
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}