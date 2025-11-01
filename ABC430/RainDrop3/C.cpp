//# of a >= A, # of b < B
#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    string s;
    cin >> N >> A >> B >> s;

    int pairs = 0;
    for (int i=0; i<N; ++i) {
        int cnt_a = 0, cnt_b = 0;
        for (int j=i; j<N; ++j) {
            if (s[j] == 'a') cnt_a++;
            else cnt_b++;

            if (cnt_b >= B) break;
            if (cnt_a >= A) {
                pairs++;
                //cout << i << ", " << j << endl;
            }
        }
    }
    cout << pairs;
}