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
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for(auto &i: a){
        cin >> i;
    }
    set<string> s;
    for(auto i = 0; i < N; ++i){
        for(auto j = 0; j < N; ++j){
            bool valid = true;
            string temp;
            for(auto k = 0; k < M; ++k){
                if(i + k >= N){
                    valid = false;
                    continue;
                }
                for(auto l = 0; l < M; ++l){
                    if(j + l >= N){
                        valid = false;
                        continue;
                    }
                    temp.push_back(a[i + k][j + l]);
                }
            }
            if(valid){
                s.insert(temp);
            }
        }
    }
    cout << s.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}