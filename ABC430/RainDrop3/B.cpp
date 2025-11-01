//#: black, .: white
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int M, N, MN;
    cin >> M >> N;

    vector v(M, vector<char>(M));
    for (int i=0; i<M; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> v[i][j];
        }
    }

    MN = (M-N+1)*(M-N+1);
    int row = 0, col = 0, ans = 0;
    set<string> s;
    while (MN--) {
        string fig = "";
        for (int i=row; i<N+row; ++i) {
            for (int j=col; j<N+col; ++j) {
                fig.push_back(v[i][j]);
                //cout << i << ", " << j << ": " << fig << endl;
            }
        }
        if (s.find(fig) == s.end()) {
            s.insert(fig);
            ans++;
        }
        col++;
        col %= (M-N+1);
        if (col == 0) row++;
    }
    cout << ans;
}