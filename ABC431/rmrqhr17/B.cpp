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
    int x;
    vector<int> v(m+1);
    vector<int> v2(m+1);
    for (int i=0;i<m;i++) {
        cin >> x;
        v[i+1] = x;
    }
    int q;
    cin >> q;
    for (int i=0;i<q;i++) {
        cin >> x;
        if (v2[x]!=0) {
            v2[x]=0;
            n-=v[x];
        }
        else {
            v2[x]=1;
            n+=v[x];
        }
        cout << n << endl;
    }
}