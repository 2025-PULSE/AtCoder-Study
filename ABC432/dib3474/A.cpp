#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> num(3);
    for (int &e: num) cin >> e;

    int result[3];
    for (int i = 0; i < 3; i++) {
        auto it = max_element(num.begin(), num.end());
        result[i] = *it;
        num.erase(it);
    }

    for (int e: result) {
        cout << e;
    }
}