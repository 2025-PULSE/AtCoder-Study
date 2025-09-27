#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q, c, l, r;
    vector<long long> A;
    vector<long long> prefix_sum;

    cin >> N >> Q;
    A.reserve(2*N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
        A[N+i] = A[i];
    }

    prefix_sum.resize(2*N + 1);
    for (int i=0; i<2*N; ++i) {
        prefix_sum[i+1] = prefix_sum[i] + A[i];
    }

    int offset = 0;
    for (int i=0; i<Q; ++i) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            cin >> c;
            offset = (offset+c) % N;
        }
        else {
            cin >> l >> r;
            cout << prefix_sum[offset + r] - prefix_sum[offset + l - 1] << '\n';
        }
    }
}