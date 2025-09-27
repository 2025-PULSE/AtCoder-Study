#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define S 524288
#define hS 262144


int main() {
    int n;
    int final=0;
    std::cin >> n;
    int a;
    std::vector<long long> v(n+2);
    std::vector<long long> ans(n+2);
    std::vector<long long> x;
    for (int i=1; i<=n; i++) {
        v[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        ans[i] = a;
        if (a==-1) {
            continue;
        }
        v[a]++;
        if (v[a]>1) {
            final++;
        }
    }
    for (long long i = 1; i <= n; i++) {
        if (v[i]<=0) {
            x.push_back(i);
        }
    }
    if (final==0) {
        int mind=0;
        std::cout << "Yes" << std::endl;
        for (int i = 0; i < n; i++) {
            if (ans[i]>0) {
                printf("%lld ", ans[i]);
            }
            else {
                printf("%lld ", x[mind]);
                mind++;
            }
        }
    }
    else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
