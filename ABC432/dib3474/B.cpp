#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    cin >> x;

    vector<int> num;
    for (int i = 0; x != 0; i++) {
        num.push_back(x % 10);
        x /= 10;
    }

    sort(num.begin(), num.end());
    for (int i = 1; i < num.size(); i++) {
        if (num[0] == 0 && num[i] != 0) {
            swap(num[0], num[i]);
            break;
        }
        else if (num[0] != 0) break;
    }
    for (int e: num) {
        cout << e;
    }
}