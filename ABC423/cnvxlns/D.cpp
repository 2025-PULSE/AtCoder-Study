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
        int N, K;
        cin >> N >> K;
        vtiii L(N);
        for(auto &[a, b, c] : L) {
            cin >> a >> b >> c;
        }
        queue<tiii> inqueue;
        vi ans(N, inf);
        unordered_map<int, int> whenleave;
        int peoplein = 0;
        
        for(int time = 0; time < 1e7; ++time){
            if(whenleave.find(time) != whenleave.end()){
                peoplein -= whenleave[time];
                whenleave.erase(time);
            }
            for(auto i = 0; i < N; ++i){
                auto &[a, b, c] = L[i];
                if(a == time){
                    inqueue.push({i, b, c});
                }
            }

            if(!inqueue.empty()){
                auto [idx, b, c] = inqueue.front();
                if(peoplein + c <= K){
                    peoplein += c;
                    ans[idx] = time;
                    whenleave[time + b] = c;
                    inqueue.pop();
                }
            }//이부분 맘에 안듬
        }

        for(const auto &i: ans){
            cout << i << endl;
        }
    }

    int32_t main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        Solve();
        return 0;
    }