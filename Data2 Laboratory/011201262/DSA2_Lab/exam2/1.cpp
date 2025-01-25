#include<bits/stdc++.h>
using namespace std;
int min_coin(vector<int> nums, int amount)
{
    int count = 0;
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= amount)
        {
            int c = amount / nums[i];
            count += c;
            amount -= c * nums[i];
        }
    }

    if(amount==0)
    {
        return count;
    }
    else
        return -1;
}

int main()
{
    vector<int> coins = {2};
    int amount = 3;
    cout << min_coin(coins, amount) << endl;
    return 0;
}
