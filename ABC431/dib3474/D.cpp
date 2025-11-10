#include <iostream>
#include <vector>
using namespace std;

vector<int> weight, head, body;
vector<vector<pair<int, long long>>> dp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    weight.resize(n);
    head.resize(n);
    body.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> head[i] >> body[i];
    }
    dp.resize(n + 1);
    dp[0].push_back({0, 0});

    for (int i = 0; i < n; i++) {
        for (auto [diff, val] : dp[i]) {
            dp[i+1].push_back({diff - weight[i], val + head[i]});
            dp[i+1].push_back({diff + weight[i], val + body[i]});
        }
    }
    long long result = 0;
    for (auto [diff, val] : dp[n]) {
        if (diff >= 0) {
            result = max(result, val);
        }
    }
    cout << result;
}