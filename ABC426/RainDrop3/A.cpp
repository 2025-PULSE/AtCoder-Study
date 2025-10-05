#include <iostream>
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;

    if (x == "Ocelot") {
        if (y == "Ocelot") cout << "Yes";
        else cout <<"No";
    }
    else if (x == "Serval") {
        if (y == "Lynx") cout << "No";
        else cout << "Yes";
    }
    else {
        cout << "Yes";
    }
}