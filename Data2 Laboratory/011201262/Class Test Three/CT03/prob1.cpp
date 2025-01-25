#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start_time;
    int finish_time;
    int weight;
};

bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.weight > a2.weight;
}

void selectActivities(const std::vector<Activity>& activities) {
    std::vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);

    int previousActivityIndex = 0;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start_time >= activities[previousActivityIndex].finish_time) {
            selectedActivities.push_back(activities[i]);
            previousActivityIndex = i;
        }
    }

    std::cout << "Selected Activities:" << std::endl;
    int totalWeight = 0;
    for (const auto& activity : selectedActivities) {
        std::cout << activity.start_time << " " << activity.finish_time << " " << activity.weight << std::endl;
        totalWeight += activity.weight;
    }

    std::cout << "Total Weight: " << totalWeight << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        std::cin >> activities[i].start_time >> activities[i].finish_time >> activities[i].weight;
    }

    std::sort(activities.begin(), activities.end(), compareActivities);

    selectActivities(activities);

    return 0;
}
