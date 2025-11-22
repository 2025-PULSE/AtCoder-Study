#include <iostream>
#include <string>
using namespace std;
string s;
bool recur(int i, int j) {
    if (s[i] + 1 != s[j]) return false;
    if (j - i == 1) return true;
    return recur(i+1, j-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int cnt = 0;
    for (int i=0; i<s.length(); ++i) {
        for (int j=i+1; j<s.length(); j+=2) {
            if (recur(i, j))
                cnt++;
        }
    }
    cout << cnt;
}