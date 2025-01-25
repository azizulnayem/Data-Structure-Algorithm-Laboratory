#include <iostream>  // Include necessary header files

using namespace std;

int profit(int Num[], int n)
{
    int profit = 0;  // Initialize a variable to store the maximum profit
    int price = Num[0];  // Initialize the price variable with the first element of the array

    // Iterate over the elements of the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        if (Num[i] < price)  // If the current element is smaller than the price
        {
            price = Num[i];  // Update the price to the current element (minimum price so far)
        }
        else
        {
            profit = max(profit, Num[i] - price);  // Calculate the profit by taking the maximum of the current profit and the difference between the current element and the price
        }
    }
    return profit;  // Return the maximum profit
}

int main()
{
    int Num[] = {7, 1, 5, 3, 6, 4};  // Initialize the array with given values
    int n = sizeof(Num) / sizeof(Num[0]);  // Calculate the size of the array

    cout << profit(Num, n) << endl;  // Call the profit function and print the result

    return 0;
}
