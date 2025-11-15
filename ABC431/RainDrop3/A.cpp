#include <iostream>
using namespace std;

int main() {
    int H, B;
    cin >> H >> B;

    if (H > B) cout << H-B;
    else cout << 0;
}