#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N, 0), queue;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (v[i] == -1) continue;
        queue.push_back(v[i]);
    }
    vector<int> check(N, 0);
    for (int &e: queue) {
        check[e - 1]++;
        if (check[e - 1] == 2) {
            cout << "No";
            return 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (v[i - 1] == -1) {
            for (int j = 1; j <= N; j++) {
                if (find(queue.begin(), queue.end(), j) == queue.end()) {
                    v[i - 1] = j;
                    queue.push_back(j);
                    break;
                }
            }
        }
    }
    cout << "Yes" << '\n';
    for (int e: v) {
        cout << e << ' ';
    }
}