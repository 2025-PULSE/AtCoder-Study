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
    int N, M, K;
    cin >> N >> M >> K;
    multiset<int> h, b; //이거 그냥 set 썼다가 WA, 입력값에 중복이 허용되어야만 한다
    int val;
    for(auto i = 0; i < N; ++i){
        cin >> val;
        h.insert(val);
    }
    for(auto i = 0; i < M; ++i){
        cin >> val;
        b.insert(val);
    }
    int cnt = 0;
    bool found = false;
    for(auto i: h){
        auto tmp = b.lower_bound(i); //set의 내장함수인 lower_bound가 std::lower_bound보다 성능이 좋다.
        if(tmp != b.end()){
            //cout << i << sp << *tmp << endl;
            cnt++;
            b.erase(tmp); // 이렇게 쓰면 상수시간으로 삭제가 가능하다. b.erase(*tmp)는 O(lgN).
        }
        if(cnt >= K){
            found = true;
            break;
        }
    }
    string ans = found ? "Yes" : "No";
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}