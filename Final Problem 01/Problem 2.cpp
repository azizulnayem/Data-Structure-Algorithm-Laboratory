#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> xCoords(n);
        vector<int> yCoords(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> xCoords[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> yCoords[i];
        }

        sort(xCoords.begin(), xCoords.end());
        sort(yCoords.begin(), yCoords.end());

        int totalCost = 0;
        for (int i = 1; i < n; ++i)
        {
            int costX = xCoords[i] - xCoords[i - 1];
            int costY = yCoords[i] - yCoords[i - 1];
            totalCost += min(costX, costY);
        }

        cout << totalCost << endl;
    }

    return 0;
}
