#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "";
    cin >> s;

    sort(s.begin(), s.end());

    int i;
    for (i=0; s[i] == '0'; ++i){}

    char tmp = s[0];
    s[0] = s[i];
    s[i] = tmp;

    cout << s;
}