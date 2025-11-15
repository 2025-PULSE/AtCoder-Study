#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ranges>
using namespace std;
using ll = long long;

ll N, M, K;
vector<ll> A;
vector<ll> B;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    A.resize(N);
    for (auto &i: A) cin >> i;
    B.resize(M);
    for (auto &i: B) cin >> i;

    ranges::sort(A);
    ranges::sort(B);
    for (ll i = 0, j = 0; i < N; i++, j++) {
        while (j < M) {
            if (A[i] <= B[j]) break;
            j++;
        }
        if (j == M) break;
        K--;
    }

    if (K <= 0) {
        cout << "Yes\n";
    } else
    cout << "No\n";
}
