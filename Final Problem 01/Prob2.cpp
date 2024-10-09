#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long minTotalCost(vector<int>& xCoords, vector<int>& yCoords)
{
    int numCities = xCoords.size();
    vector<pair<int, int>> cities;
    for (int i = 0; i < numCities; ++i)
    {
        cities.emplace_back(xCoords[i], yCoords[i]);
    }
    sort(cities.begin(), cities.end());
    long long totalCost = 0;
    int prevX = cities[0].first;
    int prevY = cities[0].second;
    for (int i = 1; i < numCities; ++i)
    {
        totalCost += min(abs(cities[i].first - prevX), abs(cities[i].second - prevY));
        prevX = cities[i].first;
        prevY = cities[i].second;
    }
    return totalCost;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int numCities;
        cin >> numCities;
        vector<int> xCoords(numCities);
        vector<int> yCoords(numCities);
        for (int i = 0; i < numCities; ++i)
        {
            cin >> xCoords[i];
        }
        for (int i = 0; i < numCities; ++i)
        {
            cin >> yCoords[i];
        }
        long long result = minTotalCost(xCoords, yCoords);
        cout << result << endl;
    }
    return 0;
}
