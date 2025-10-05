#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q, x, y, cnt;
    cin >> N >> Q;
    vector<int> v;
    v.reserve(N);

    for (int i=1; i<=N; ++i) v.push_back(i);

    while (Q--) {
        cnt = 0;
        cin >> x >> y;
        for (int i=0; i<x; ++i) {
            if (v[i] <= x) {
                v[i] = y;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}