#include<bits/stdc++.h>  // Include necessary header files

using namespace std;

int min_coin(vector<int> nums, int amount)
{
    int count = 0;  // Initialize a variable to keep track of the count of coins used
    sort(nums.rbegin(), nums.rend());  // Sort the denominations of coins in descending order

    // Iterate over the denominations
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= amount)  // If the current coin denomination is less than or equal to the remaining amount
        {
            int c = amount / nums[i];  // Calculate how many times the current coin can be used
            count += c;  // Add the count of coins used
            amount -= c * nums[i];  // Subtract the total amount covered by the coins used so far
        }
    }

    if(amount==0)  // If the amount is completely covered by the coins
    {
        return count;  // Return the minimum number of coins used
    }
    else
        return -1;  // If the amount cannot be formed using the given denominations, return -1
}

int main()
{
    vector<int> coins = {2};  // Set of coin denominations
    int amount = 3;  // Target amount
    cout << min_coin(coins, amount) << endl;  // Call the min_coin function and print the result
    return 0;
}
