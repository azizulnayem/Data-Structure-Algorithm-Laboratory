#include <bits/stdc++.h>
using namespace std;
bool compare(vector<int> &p1, vector<int> &p2)
{

    return p1[1] < p2[1];
}
int minArrows(vector<vector<int>> &points)
{

    sort(points.begin(), points.end(), compare);


    int end = points[0][1];


    int ans = 1;


    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= end)
        {
            continue;
        }
        else
        {


            end = points[i][1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    cout << minArrows(points) << endl;
}
