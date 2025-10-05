#include <iostream>
#include <string>
using namespace std;

int change(string& s, int cnt, char c) {
    char not_c = '1';
    if (c == '1') not_c = '0';

    if (s.find(not_c) == s.npos) return cnt;
    size_t first = s.find(not_c);
    size_t last = s.rfind(not_c);
    size_t tmp;

    if (first < s.size()-1-last) {
        if (s.front() == '1') tmp = '0';
        else tmp = '1';
        s.erase(0, 1);
        s.insert(s.size()/2, 1, tmp);
    }
    else {
        if (s.back() == '1') tmp = '0';
        else tmp = '1';
        s.erase(s.size()-1, 1);
        s.insert(s.size()/2, 1, tmp);
    }

    cnt++;
    cnt = change(s, cnt, c);
    return cnt;
}

int main() {
    int T, n, res0, res1;
    string s;
    cin >> T;

    while (T--) {
        cin >> n >> s;
        res0 = change(s, 0, 0);
        res1 = change(s, 0, 1);
        if (res0 > res1) cout << res1;
        else             cout << res0;
    }
}