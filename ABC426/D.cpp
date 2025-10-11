#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int one=0,beforeone=0,afterone=0;
        int zero=0,beforezero=0,afterzero=0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                one++;
                beforeone++;
                if (i!=0) {
                    if (s[i-1] == '0') {
                        if (afterzero<beforezero) {
                            afterzero=beforezero;
                        }
                        beforezero=0;
                    }
                }

            }
            if (s[i] == '0') {
                zero++;
                beforezero++;
                if (i!=0) {
                    if (s[i-1] == '1') {
                        if (afterone<beforeone) {
                            afterone=beforeone;
                        }
                        beforeone=0;
                    }
                }
            }
        }
        if (afterone<beforeone) {
            afterone=beforeone;
        }
        if (afterzero<beforezero) {
            afterzero=beforezero;
        }
        if (one==0 || zero==0) {
            cout << 0 << endl;
            continue;
        }
        if (one+zero*2-afterzero*2 < zero+one*2-afterone*2) {
            cout << one+zero*2-afterzero*2 << endl;
        }
        else {
            cout << zero+one*2-afterone*2 << endl;
        }
    }
}