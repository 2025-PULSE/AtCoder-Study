#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define S 524288
#define hS 262144
int main() {
    long long n,q;
    long long y;
    std::cin >> n >> q;
    std::vector<long long> v(S);
    for (long long i = 0; i < n; i++) {
        long long x=i+hS;
        std::cin >> y;
        while (x>0) {
            v[x]+=y;
            x/=2;
        }
    }
    int a,b,c;
    long long sum=0;
    long long cur=0;
    for (long long i = 0; i < q; i++) {
        std::cin >> a >> b;
        if (a==2) {
            std::cin >> c;
            long long right=hS+(c-1+cur)%n;
            long long left=hS+(b-1+cur)%n;
            if (left>right) {
                long long g=S-1;
                while (left<=g) {
                    if (left%2==1) {
                        sum+=v[left];
                        left++;
                    }
                    if (g%2==0) {
                        sum+=v[g];
                        g--;
                    }
                    left/=2;
                    g/=2;
                }
                g=hS;
                while (g<=right) {
                    if (g%2==1) {
                        sum+=v[g];
                        g++;
                    }
                    if (right%2==0) {
                        sum+=v[right];
                        right--;
                    }
                    right/=2;
                    g/=2;
                }
                std::cout << sum << std::endl;
                sum=0;
            }
            else{
                while (left<=right) {
                    if (left%2==1) {
                        sum+=v[left];
                        left++;
                    }
                    if (right%2==0) {
                        sum+=v[right];
                        right--;
                    }
                    left/=2;
                    right/=2;
                }
                std::cout << sum << std::endl;
                sum=0;
            }
        }
        else {
            cur+=b;
            cur%=n;
        }
    }
}