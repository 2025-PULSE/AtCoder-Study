#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int m;
    int k;
    cin >> n;
    cin >> m;
    cin >> k;
    int x;
    vector<int> v(n);
    vector<int> v2(m);
    for (int i=0;i<n;i++) {
        cin >> x;
        v[i] = x;
    }
    for (int i=0;i<m;i++) {
        cin >> x;
        v2[i] = x;
    }
    sort(v2.begin(),v2.end());
    sort(v.begin(),v.end());
    int u=0;
    int d=0;
    int sum=0;
    while (u<n && d<m) {
        if (v[u]<=v2[d]) {
            sum++;
            u++;
            d++;
        }
        else {
            d++;
        }
    }
    if (sum>=k) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}