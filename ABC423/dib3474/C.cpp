#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    vector<int> door(N);
    for (int &e : door) {
        cin >> e;
    }
    int start, end;
    for (start = 0 ; start < N; start++) {
        if (door[start] == 0) break;
    }
    for (end = N - 1; end >= 0; end--) {
        if (door[end] == 0) break;
    }
    int result = 0;
    for (int i = start; i < R; i++) {
        if (door[i] == 0) result += 1;
        else result += 2;
    }
    for (int i = R; i <= end; i++) {
        if (door[i] == 0) result += 1;
        else result += 2;
    }

    cout << result;
}