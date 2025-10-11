#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (auto i=s.begin(); i<s.end()-1; ++i) {
        if (*i != *(i+1)) {
            if (i == s.begin()) {
                if (*i == *(i+2)) cout << *(i+1);
                else cout << *i;
            }
            else {
                if (*i == *(i-1)) cout << *(i+1);
                else cout <<*i;
            }
            return 0;
        }
    }
}