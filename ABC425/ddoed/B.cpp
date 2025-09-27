#include <bits/stdc++.h>

using namespace std;

#define MOD 1e9+7
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	set<int> s;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] != -1) {
			if (s.find(a[i]) != s.end()) {
				cout << "No";
				return 0;
			}
			s.insert(a[i]);
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (s.find(i) == s.end()) v.push_back(i);
	}
	cout << "Yes" << '\n';
	int idx = 0;
	for (int i = 0;i < n; i++) {
		if (a[i] == -1) {
			cout << v[idx] << ' ';
			idx++;
		}
		else cout << a[i] << ' ';
	}
}