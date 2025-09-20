#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> door(N);
    for (int &e : door) {
        cin >> e;
    }
    int start, end;
    for (start = 0 ; start < N; start++) {
        if (door[start] == 1) break;
    }
    for (end = N - 1; end >= 0; end--) {
        if (door[end] == 1) break;
    }
    int result = end - start;
    if (result < 0) cout << 0;
    else cout << result;
}