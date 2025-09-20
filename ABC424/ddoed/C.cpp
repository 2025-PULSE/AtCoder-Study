#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

vector<int> adj[200001];
vector<bool> learned(200001, false);

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) learned[i] = true;
		else {
			if (a > 0) {
				adj[a].push_back(i);
			}
			if (b > 0) {
				adj[b].push_back(i);
			}
		}
	}
	
	queue<int> q;
	int cnt = 0;

	for (int i = 1;i <= n;i++) {
		if (learned[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!learned[cur]) continue;
		cnt++;
		for (int nxt : adj[cur]) {
			if (!learned[nxt]) {
				learned[nxt] = true;
				q.push(nxt);
			}
		}
	}

	cout << cnt;
}