#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int main() {
    string x,y;
    cin >> x >> y;
    if (x == y) {
        cout << "Yes" << endl;
        return 0;
    }
    if (x=="Serval" && y=="Ocelot" || x=="Lynx") {
        cout << "Yes" << endl;
        return 0;
    }
    if (x=="Serval" && y=="Lynx" || x=="Ocelot") {
        cout << "No" << endl;
        return 0;
    }
}