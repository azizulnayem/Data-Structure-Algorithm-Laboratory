#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    unordered_map<int, int> sortedPositions;
    for (int i = 0; i < N; ++i) {
        sortedPositions[sortedA[i]] = i + 1;
    }

    for (int i = 0; i < N; ++i) {
        cout << sortedPositions[A[i]] << " ";
    }

    cout << endl;

    return 0;
}
