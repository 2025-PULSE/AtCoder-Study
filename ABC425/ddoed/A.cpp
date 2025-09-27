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
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		sum += pow(-1, i) * pow(i, 3);
	}
	cout << sum;
}