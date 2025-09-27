#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result += pow(-1, i) * pow(i, 3);
    }
    cout << result;
}