#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	map<int, int> cnt;
	vector<int> ans;
	
	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		cnt[a]++;
		if (cnt[a] == m) ans.push_back(a);
	}

	for (auto i : ans) {
		cout << i << ' ';
	}
}