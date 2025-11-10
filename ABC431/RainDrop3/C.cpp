#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int heads, bodies, robots, num;
    cin >> heads >> bodies >> robots;

    vector<int> head_wei(heads), body_wei(bodies);
    for (int i=0; i<heads; ++i) {
        cin >> num;
        head_wei[i] = num;
    }
    for (int i=0; i<bodies; ++i) {
        cin >> num;
        body_wei[i] = num;
    }

    sort(head_wei.begin(), head_wei.end());
    sort(body_wei.begin(), body_wei.end());

    int cnt = 0;
    for (int i=0; i<min(heads, bodies); ++i) {
        auto it = lower_bound(body_wei.begin(), body_wei.end(), head_wei[i]);
        if (it == body_wei.end()) break;
        //cout << cnt << ") " << head_wei[i] << " " << *it << endl;
        cnt++;
        *it = -1;
    }

    //cout << cnt << " " << robots << endl;
    if (cnt >= robots) cout << "Yes";
    else cout << "No";
}