#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
int H, W;
int ans = 0;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<vector<char>> board;
queue<pll> q;
void bfs(){
    for (int i = 0; ; i++){
        if (q.empty()) break;
        queue<pll> tmp;
        while (!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (board[nx][ny] == '#') continue;
                tmp.emplace(nx, ny);
            }
            board[x][y] = '#';
        }

        while (!tmp.empty()){
            auto [x, y] = tmp.front(); tmp.pop();
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (board[nx][ny] == '#') cnt++;
            }

            if (cnt == 1){
                q.emplace(x, y); ans++;
            }
        }        
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> H >> W;
    board.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> board[i][j];
            if (board[i][j] == '#'){
                q.emplace(i, j);
                ans++;
            }
        }
    }

    bfs();
    cout << ans;
    return 0;
}
