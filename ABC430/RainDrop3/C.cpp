//# of a >= A, # of b < B
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, A, B;
    string s;
    cin >> N >> A >> B >> s;

    long long pairs = 0;
    vector<int> prefix_a(N+1), prefix_b(N+1);
    for (int i=0; i<N; ++i) {
        prefix_a[i+1] = prefix_a[i] + (s[i] == 'a');
        prefix_b[i+1] = prefix_b[i] + (s[i] == 'b');
    }

    for (int l=1; l<=N; ++l) {
        int target_a = A + prefix_a[l-1];
        int target_b = B + prefix_b[l-1];

        auto it_a = lower_bound(prefix_a.begin()+l, prefix_a.end(), target_a);
        auto it_b = lower_bound(prefix_b.begin()+l, prefix_b.end(), target_b);

        int r_min = it_a - prefix_a.begin();
        int r_max = it_b - prefix_b.begin();

        pairs += max(0, r_max - r_min);
    }
    cout << pairs;
}