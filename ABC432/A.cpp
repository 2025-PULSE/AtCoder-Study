#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(3);
    for (int& i : v)
        cin >> i;

    sort(v.begin(), v.end(), greater<int>());

    for (int& i : v)
        cout << i;
}