#include <iostream>
using namespace std;

int main() {
    int h, b;
    cin >> h >> b;

    if (h - b <= 0) cout << '0';
    else cout << h - b;
}