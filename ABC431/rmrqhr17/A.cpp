#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int m;
    cin >> n;
    cin >> m;
    if (n-m<0) {
        cout << 0 << endl;
        return 0;
    }
    cout << n-m << endl;
}