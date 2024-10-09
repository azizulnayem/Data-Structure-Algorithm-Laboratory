#include <iostream>
#include <vector>

using namespace std;

int ways(int sum, vector<int>& coins)
{
    int n = coins.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = coins[i]; j <= sum; ++j)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main()
{
    int sum1 = 4;
    vector<int> coins1 = {1, 2, 3};
    cout << "Number of ways for sum 4: " << ways(sum1, coins1) << endl;

    int sum2 = 10;
    vector<int> coins2 = {2, 5, 3, 6};
    cout << "Number of ways for sum 10: " << ways(sum2, coins2) << endl;

    return 0;
}
