#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
int main() {
    long long n;
    std::cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i*i*i;
        }
        else {
            sum += -i*i*i;
        }
    }
    std::cout << sum;
}