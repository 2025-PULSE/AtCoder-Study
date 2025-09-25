#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    int a,b,c;
    int x,y;
    std::vector<int> comp;
    std::cin >> a >> b >> c;
    std::vector<std::vector<int>> v(a+1);
    for (int i = 1; i <= c; i++) {
        std::cin >> x >> y;
        v[x].push_back(y);
        if (v[x].size() == b) {
            comp.push_back(x);
        }
    }
    for (int i = 0; i < comp.size(); i++) {
        printf("%d ", comp[i]);
    }
}