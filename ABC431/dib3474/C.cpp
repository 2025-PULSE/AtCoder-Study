#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> head(n), body(m);
    for (int& e: head) cin >> e;
    for (int& e: body) cin >> e;

    sort(head.begin(), head.end());
    sort(body.begin(), body.end());

    int count = 0, i = 0, j = 0;
    for (; i < n; i++) {
        for (;j < m; j++) {
            if (head[i] <= body[j]) {
                count++;
                j++;
                break;
            }
        }
    }
    if (k <= count) cout << "Yes";
    else cout << "No";
}