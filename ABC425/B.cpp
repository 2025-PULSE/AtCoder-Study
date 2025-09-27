#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> A, P;

    cin >> N;
    A.reserve(N);
    P.resize(N);
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
        if (num != -1) P[i] = num;
    }

    auto it = find(A.begin(), A.end(), -1);
    int num = 1;
    while(it != A.end()) {
        int idx = it - A.begin();
        if (find(P.begin(), P.end(), num) == P.end()) {
            P[idx] = num;
            A[idx] = num;
            it = find(A.begin(), A.end(), -1);
        }
        num++;
    }

    if (accumulate(P.begin(), P.end(), 0) == (N*(N+1)/2)) {
        cout << "Yes" << endl;
        for (int i : P) cout << i << " ";
    }
    else cout << "No";
}