#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// pruning을 잘 해줘야 하는 backtracking 문제입니다.

char c[9][9];
int mt[9][9];
int H, W;
void init(){
    memset(mt, 0, sizeof(mt));
    memset(c, 0, sizeof(c));
    cin >> H >> W;
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> c[i][j];
        }
    }

    for (int i = 1; i < H; i++){
        for (int j = 1; j < W; j++){
            if (c[i][j] == '#' && c[i + 1][j] == '#' && c[i][j + 1] == '#' && c[i + 1][j + 1] == '#'){
                mt[i][j] = 1;
            }
        }
    }
}
int cnt = 0;
int ans = 100;
void solve(int x, int y){
    if (cnt == ans){
        return;
    }
    if (x == H + 1){
        ans = min(cnt, ans);
        return;
    }
    int nx, ny;
    if (y == W){
        nx = x + 1; ny = 1;
    }
    else{
        nx = x; ny = y + 1;
    }
    if (c[x][y] == '.'){
        solve(nx, ny);
        return;
    }

    {
        int txy = mt[x - 1][y - 1];
        int tx = mt[x - 1][y];
        int ty = mt[x][y - 1];
        int tt = mt[x][y];

        {

            c[x][y] = '.';
            cnt++;

            mt[x - 1][y - 1] = 0;
            mt[x - 1][y] = 0;
            mt[x][y - 1] = 0;
            mt[x][y] = 0;

            solve(nx, ny);

            mt[x - 1][y - 1] = txy;
            mt[x - 1][y] = tx;
            mt[x][y - 1] = ty;
            mt[x][y] = tt;

            cnt--;
            c[x][y] = '#';
        }
    }

    if (!mt[x - 1][y - 1]){
        solve(nx, ny);
    }

    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--){
        ans = 100;
        init();
        solve(2, 2);
        cout << ans << "\n";
    }
    return 0;
}
