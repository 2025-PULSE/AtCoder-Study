#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int people[11] = {0}, result[10] = {0}, index = 0;
    while (K--) {
        int a, b;
        cin >> a >> b;
        people[a]++;
        if (people[a] == M) result[index++] = a;
    }
    for (int i = 0; i < 10; i++) {
        if (result[i] != 0) {
            cout << result[i] << ' ';
        }
    }
}