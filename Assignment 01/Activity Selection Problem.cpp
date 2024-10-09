#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start_time;
    int finish_time;
};

bool compare(Activity a1, Activity a2) {
    return a1.finish_time < a2.finish_time;
}

vector<Activity> greedyActivitySelector(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);

    int k = 0;
    int n = activities.size();

    for (int m = 1; m < n; ++m) {
        if (activities[m].start_time >= activities[k].finish_time) {
            selectedActivities.push_back(activities[m]);
            k = m;
        }
    }

    return selectedActivities;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter the start and finish times of the activities:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start_time >> activities[i].finish_time;
    }

    vector<Activity> selectedActivities = greedyActivitySelector(activities);

    cout << "Total Selected Activities: " << selectedActivities.size() << endl;
    cout << "Selected Activities: " << endl;
    for (const auto& activity : selectedActivities) {
        cout << "Start Time: " << activity.start_time << ", Finish Time: " << activity.finish_time << endl;
    }

    return 0;
}
