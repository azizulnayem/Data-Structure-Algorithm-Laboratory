#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    char club_id;
    int start_time;
    int finish_time;
};

bool compare(Event e1, Event e2) {
    return e1.finish_time < e2.finish_time;
}

vector<char> selectEvents(vector<Event>& events, int cleanup_time) {
    sort(events.begin(), events.end(), compare);

    vector<char> chosenClubs;
    int n = events.size();
    int current_time = 0;

    for (int i = 0; i < n; ++i) {
        if (events[i].start_time >= current_time) {
            chosenClubs.push_back(events[i].club_id);
            current_time = events[i].finish_time + cleanup_time;
        }
    }

    return chosenClubs;
}

int main() {
    int n;
    cout << "Enter the number of events: ";
    cin >> n;

    vector<Event> events(n);

    cout << "Enter the club id, start time, and duration of events:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> events[i].club_id >> events[i].start_time >> events[i].finish_time;
        events[i].finish_time += events[i].start_time;
    }

    int cleanup_time;
    cout << "Enter the cleanup time: ";
    cin >> cleanup_time;

    vector<char> chosenClubs = selectEvents(events, cleanup_time);

    if (chosenClubs.empty()) {
        cout << "No clubs chosen." << endl;
    } else {
        cout << "Chosen clubs:" << endl;
        for (const auto& club : chosenClubs) {
            cout << club << endl;
        }
    }

    return 0;
}
