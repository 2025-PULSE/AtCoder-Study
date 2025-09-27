#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    int N, Q, tmp, tmp1, tmp2;
    vector<int> A;
    typedef tuple<int, int, int> t;
    vector<t> query;

    cin >> N >> Q;
    A.reserve(N+1);
    for (int i=0; i<N; ++i) {
        cin >> tmp;
        A.push_back(tmp);
    }

    query.reserve(Q);
    for (int i=0; i<Q; ++i) {
        cin >> tmp;
        if (tmp == 1) {
            cin >> tmp1;
            query.emplace_back(tmp, tmp1, 0);
        }
        else {
            cin >> tmp1 >> tmp2;
            query.emplace_back(tmp, tmp1, tmp2);
        }
    }

    for (auto q : query) {
        if (get<0>(q) == 1) {
            while (get<1>(q)--) {
                A.push_back(A.front());
                A.erase(A.begin());
            }
        }
        else {
            int sum = 0;
            for (int i=get<1>(q)-1; i<get<2>(q); ++i) {
                sum += A[i];
            }
            cout << sum << endl;
        }
    }
}