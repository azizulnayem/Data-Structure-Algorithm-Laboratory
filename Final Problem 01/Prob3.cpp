
#include <iostream>
#include <vector>
using namespace std;
int countWaysToMakeSum(int sum, vector<int>& coins)
{
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int i = coin; i <= sum; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }
    return dp[sum];
}
int main()
{
    int sum, numCoins;
    cin >> sum >> numCoins;
    vector<int> coins(numCoins);
    for (int i = 0; i < numCoins; ++i)
    {
        cin >> coins[i];
    }
    int ways = countWaysToMakeSum(sum, coins);
    cout << "Number of ways: " << ways << endl;
    return 0;
}
