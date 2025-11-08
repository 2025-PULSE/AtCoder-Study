#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, n, q, Q;
    cin >> x >> n;
    vector<int> part(n);
    vector<bool>attached(n);
    for (int &e : part) cin >> e;
    cin >> q;
    while (q--) {
        cin >> Q;
        Q--;
        if (!attached[Q]) {
            x += part[Q];
        }
        else {
            x -= part[Q];
        }
        cout << x << '\n';
        attached[Q] = !attached[Q];
    }
}