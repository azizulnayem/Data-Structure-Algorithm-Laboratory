#include <iostream>
#include <vector>

using namespace std;

int maxConsecutiveDays(const vector<int>& workload) {
    int maxDays = 0;
    int currentDays = 0;

    for (int hours : workload) {
        if (hours > 5) {
            currentDays++;
            maxDays = max(maxDays, currentDays);
        } else {
            currentDays = 0;
        }
    }

    return maxDays;
}

int main() {
    int N;
    cin >> N;

    vector<int> workload(N);
    for (int i = 0; i < N; ++i) {
        cin >> workload[i];
    }

    int employeeRating = maxConsecutiveDays(workload);
    cout << employeeRating << endl;

    return 0;
}
