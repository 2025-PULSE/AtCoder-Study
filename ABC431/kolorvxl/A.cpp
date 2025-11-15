#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ranges>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll H ,B;
    cin >> H >> B;
    cout << max(0ll, H - B);
}