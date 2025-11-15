#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int N, W, H, B;
    cin >> N;

    long long wei_head = 0, wei_body = 0,
              happy_head = 0, happy_body = 0;
    vector<tuple<int, int, int, int>> v;
    v.reserve(N);
    for (int i=0; i<N; ++i) {
        cin >> W >> H >> B;
        v.emplace_back(W, H, B, H-B);
        wei_body += W;
        happy_body += B;
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return get<3>(a) > get<3>(b);
    });

    for (int i=0; i<N; ++i) {
        happy_head += get<1>(v[i]);
        happy_body -= get<2>(v[i]);
        wei_head += get<0>(v[i]);
        wei_body -= get<0>(v[i]);

        if (wei_head > wei_body) {
            happy_head -= get<1>(v[i]);
            happy_body += get<2>(v[i]);
            wei_head -= get<0>(v[i]);
            wei_body += get<0>(v[i]);
            break;
        }
    }
    cout << happy_head + happy_body;
}