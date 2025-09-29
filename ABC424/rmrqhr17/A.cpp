#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    int a,b,c;
    std::cin >> a >> b >> c;
    if (a==b || a==c || b==c) {
        printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}