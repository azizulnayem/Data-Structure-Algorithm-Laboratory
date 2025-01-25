#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<pair<double, double>> findSmallestIntervals(vector<double>& points) {
    sort(points.begin(), points.end());  // Sort the points in ascending order
    vector<pair<double, double>> intervals;  // Vector to store the intervals

    double left = points[0];  // Initialize the left endpoint
    double right = left + 1;  // Initialize the right endpoint

    for (int i = 1; i < points.size(); i++) {
        if (points[i] > right) {
            intervals.push_back(make_pair(left, right));  // Add the interval to the vector
            left = points[i];  // Update the left endpoint
            right = left + 1;  // Update the right endpoint
        } else {
            right = points[i] + 1;  // Update the right endpoint
        }
    }

    intervals.push_back(make_pair(left, right));  // Add the last interval to the vector

    return intervals;
}

int main() {
    int n;
    cin >> n;  // Read the number of points

    vector<double> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];  // Read the points
    }

    vector<pair<double, double>> intervals = findSmallestIntervals(points);

    cout << "Number of intervals: " << intervals.size() << endl;
    cout << "Intervals:" << endl;
    for (const auto& interval : intervals) {
        cout << fixed << setprecision(1) << "(" << interval.first << ", " << interval.second << ")" << endl;
    }

    return 0;
}
