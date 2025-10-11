#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    string s;
    cin >> s;
    string same;
    string last;
    int sl=0;
    int ll=0;
    for (int i = 0; i < s.length(); i++) {
        if (i==0) {
            same.push_back(s[i]);
            sl++;
        }
        else {
            if (i==1 && same[0]!=s[i]) {
                last.push_back(s[i]);
                ll++;
            }
            else {
                if (same[0]==s[i]) {
                    same.push_back(s[i]);
                    sl++;
                }
                else {
                    last.push_back(s[i]);
                    ll++;
                }
            }
        }
    }
    if (same.length()>=last.length()) {
        cout << last[0];
    }
    else {
        cout << same[0];
    }
}