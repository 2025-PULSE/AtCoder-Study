#include <iostream>
#include <vector>
using namespace std;

int check(vector<pair<int, int>>& skill, vector<int>& result, int index, vector<int>& visited) {
    if (result[index] == 1) return 1;
    if (visited[index] == -1) return 0;
    visited[index] = -1;
        
    if (index != skill[index].first - 1) {
        if (check(skill, result, skill[index].first - 1, visited)) {
            result[index] = 1;
            visited[index] = 1;
            return 1;
        }
    }
    if (index != skill[index].second - 1) {
        if (check(skill, result, skill[index].second - 1, visited)) {
            result[index] = 1;
            visited[index] = 1;
            return 1;
        }
    }
    visited[index] = 1;
    return result[index];
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> skill(N);
    vector<int> result(N, 0), visited(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> skill[i].first >> skill[i].second;
        if (skill[i].first == 0 && skill[i].second == 0) {
            result[i] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (result[i] == 1) continue;
        check(skill, result, i, visited);
    }
    int count = 0;
    for (auto& e : result) {
        count += e;
    }
    cout << count;
}