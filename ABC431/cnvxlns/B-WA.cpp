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
    /*
    // 비트마스킹 한번 써보고 싶어서 써봤다.
    // 하지만 N범위를 확인했어야 했다.
    */
    int X;
    int N;
    cin >> X >> N;
    vi W(N);
    int attached = 0; // 64비트 정수이기 때문에 N > 64면 터진다.
    for(auto &i: W){
        cin >> i;
    }
    int Q;
    cin >> Q;
    while(Q--){
        int query;
        cin >> query;
        if(attached & (1 << query)){
            X -= W[query - 1];
        }else{
            X += W[query - 1];
        }
        attached ^= (1 << query);
        cout << X << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}