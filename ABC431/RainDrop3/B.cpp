#include <iostream>
#include <vector>
using namespace std;

int main() {
    int weight, types, queries, num;
    vector<int> type_attached(101, 0), type_num(101, 0);

    cin >> weight >> types;
    for (int i=1; i<=types; ++i) {
        cin >> num;
        type_num[i] = num;
    }

    cin >> queries;
    while (queries--) {
        cin >> num;
        if (type_attached[num]) {
            weight -= type_num[num];
            type_attached[num] = 0;
            cout << weight << endl;
        }
        else {
            weight += type_num[num];
            type_attached[num] = 1;
            cout << weight << endl;
        }
    }
}