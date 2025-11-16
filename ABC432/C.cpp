#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    vector<long long> A(n), yA(n);
    for (long long& i : A)
        cin >> i;
    for (int i=0; i<n; ++i)
        yA[i] = A[i] * y;

    sort(A.begin(), A.end(), greater<long long>());
    sort(yA.begin(), yA.end(), greater<long long>());

    long long min = yA.back(), diff = y-x, cnt = 0;
    for (int i=0; i<n; ++i) {
        if (!((yA[i] - min) % diff == 0 && A[i] * diff >= yA[i] - min)) {
            cout << -1;
            return 0;
        }
        int tmp = (yA[i] - min) / diff;
        cnt += A[i] - tmp;
    }
    cout << cnt;
}