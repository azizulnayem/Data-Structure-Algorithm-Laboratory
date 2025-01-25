#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSaveAllPatients(vector<int>& vaccines, vector<int>& midichlorians) {
    sort(vaccines.begin(), vaccines.end());  // Sort the vaccine strengths in ascending order
    sort(midichlorians.begin(), midichlorians.end());  // Sort the midichlorians counts in ascending order

    for (size_t i = 0; i < vaccines.size(); ++i) {
        if (vaccines[i] <= midichlorians[i]) {
            return false;  // If any patient can't be cured, return false
        }
    }

    return true;  // All patients can be cured
}

int main() {
    int N;
    cin >> N;

    vector<int> vaccines(N);
    vector<int> midichlorians(N);

    for (int i = 0; i < N; ++i) {
        cin >> vaccines[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> midichlorians[i];
    }

    if (canSaveAllPatients(vaccines, midichlorians)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
