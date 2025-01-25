#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TripRequest {
    char id;
    int start;
    int duration;
};

int maxProfit(vector<TripRequest>& requests, int breakTime) {
    sort(requests.begin(), requests.end(), [](const TripRequest& a, const TripRequest& b) {
        return a.duration > b.duration;  // Sort requests in descending order of duration
    });

    int maxProfit = 0;
    vector<TripRequest> chosenRequests;

    for (const auto& request : requests) {
        bool canTakeRequest = true;

        for (const auto& chosen : chosenRequests) {
            if (request.start - chosen.start < breakTime || chosen.start + chosen.duration > request.start) {
                canTakeRequest = false;  // Overlapping or insufficient break time, cannot take the request
                break;
            }
        }

        if (canTakeRequest) {
            maxProfit += request.duration;
            chosenRequests.push_back(request);
        }
    }

    cout << "Profit: " << chosenRequests.size() << " x " << breakTime << " = " << chosenRequests.size() * breakTime << endl;
    cout << "Chosen Tasks:" << endl;
    for (const auto& chosen : chosenRequests) {
        cout << chosen.id << endl;
    }

    return maxProfit;
}

int main() {
    vector<TripRequest> requests = {
        {'a', 2, 8},
        {'b', 3, 4},
        {'c', 7, 1},
        {'d', 8, 1},
        {'e', 10, 1}
    };

    int M = 10;  // Amount charged for each trip
    int N = 1;   // Number of trip requests
    int X = 4;   // Break time between trips

    // Adjusting the start times based on M and N
    for (auto& request : requests) {
        request.start = M * (request.start - 1);
    }

    maxProfit(requests, X);

    return 0;
}
