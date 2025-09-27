#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    vector<long long> q(N), sum((2 * N)+1);

    for (auto &e: q) {
        cin >> e;
    }

    for (int i = 0; i < N; i++) {
        q.push_back(q[i]);
    }

    sum[0] = 0;
    for (int i = 1; i < 2 * N; i++) {
        sum[i] = sum[i - 1] + q[i - 1];
    }

    int base_idx = 0;
    while(Q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int c;
            cin >> c;
            base_idx = (base_idx + c) % N;
        }
        else if (query == 2) {
            int s, e, total = 0;
            cin >> s >> e;
            int start_idx = base_idx + s - 1;
            int end_idx = base_idx + e;
            cout << sum[end_idx] - sum[start_idx] << '\n';
        }
    }
}