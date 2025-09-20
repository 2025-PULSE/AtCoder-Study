#include <iostream>
using namespace std;

int main() {
    int X, C;
    cin >> X >> C;

    int result = 0, pee = 0;
    while(result + pee <= X) {
        result += 1000;
        pee += C;
    }
    result -= 1000;
    cout << result;
}