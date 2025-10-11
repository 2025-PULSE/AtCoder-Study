#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int find_set(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_set(int a, int b, vector<int>& parent) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, x, y;
    cin >> N >> Q;

    vector<int> parent(N+2);
    iota(parent.begin(), parent.end(), 0);

    vector<long long> count(N+2, 1);

    while (Q--) {
        cin >> x >> y;
        long long cnt = 0;

        for (int v = find_set(1, parent); v <= x; v=find_set(v, parent)) {
            cnt += count[v];
            count[y] += count[v];
            count[v] = 0;

            union_set(v, v+1, parent);
        }
        cout << cnt << '\n';
    }
    return 0;
}