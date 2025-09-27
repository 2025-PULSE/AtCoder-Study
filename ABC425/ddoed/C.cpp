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

	int n, q;
	cin >> n >> q;
	vector<int> a(n+1);
	vector<int> sums(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) sums[i] = a[i];
		else sums[i] = a[i] + sums[i - 1];
	}

	int front = 0;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			int c;
			cin >> c;
			front += c;
			front %= n;
		}
		else if (x == 2) {
			int l, r;
			cin >> l >> r;
			r--;l--;
			int start = (front + l)%n;
			int end = (front + r)%n;
			if (start == 0) cout << sums[end] << '\n';
			else if (start <= end) {
				cout << sums[end] - sums[start - 1] << '\n';
			}
			else if (start > end) {
				cout << sums[end] + (sums[n - 1] - sums[start - 1]) << '\n';
			}
		}
	}
}