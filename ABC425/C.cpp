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

int base;
vi segtree;
vi B, A;

void init(int N){
    for(base = 1; base <= N; base *= 2);
    segtree.resize(base);
    for(auto i: A){
        segtree.push_back(i);
    }
    for(auto i = A.size(); i < base * 2; ++i){
        segtree.push_back(0);
    }
    for(auto i = base - 1; i > 0; --i){
        segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
    }
}

int query(int lo, int hi){
    lo += base - 1, hi += base - 1;
    int ret = 0;
    while(lo <= hi){
        if(lo & 1){
            ret += segtree[lo];
            lo++;
        }
        if(hi % 2 == 0){
            ret += segtree[hi];
            hi--;
        }
        lo /= 2;
        hi /= 2;
    }
    return ret;
}

void Solve() {
    int N, Q;
    cin >> N >> Q;
    B.resize(N);
    for(auto &i: B){
        cin >> i;
    }
    REP(i, 2)
    for(const auto &i: B){
        A.push_back(i);
    }
    A.pop_back();
    init(N * 2);
    // for(int i = 1; i < base * 2; ++i){
    //     cout << segtree[i] << sp;
    //     if(i == 1 || i == 3 || i == 7 || i == 15){
    //         cout << endl;
    //     }
    // }
    cout << endl;
    int pointer = 0;
    REP(i, Q){
        int q;
        cin >> q;
        if(q == 1){ // rotate
            int c;
            cin >> c;
            pointer += c;
            pointer %= N;
        }else{  //query
            int l, r;
            cin >> l >> r;
            l += pointer;
            r += pointer;
            cout << query(l, r) << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}