#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int h, w;

bool isValid(int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    queue<pii> q;
    vector<vector<int>> visited(h + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                visited[i][j] = 1;
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        int qSize = q.size();
        vector<pii> tmp;
        while (qSize--) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nxtX = x + dx[i];
                int nxtY = y + dy[i];
                if (isValid(nxtX, nxtY) && !visited[nxtX][nxtY]) {
                    int cnt = 0;
                    for (int j = 0; j < 4; j++) {
                        int nx = nxtX + dx[j];
                        int ny = nxtY + dy[j];
                        if (isValid(nx, ny) && visited[nx][ny]) cnt++;
                    }
                    if (cnt == 1) {
                        tmp.push_back({ nxtX, nxtY });
                    }
                }
            }
        }
        // visited를 나중에 처리했어야 하는데 위에서 바로 확정하고 queue에 넣어버렸습니다..
        for (auto [x, y] : tmp) {
            visited[x][y] = 1;
            q.push({x,y});
        }
    }

    int total = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (visited[i][j]) total++;

    cout << total;
}
