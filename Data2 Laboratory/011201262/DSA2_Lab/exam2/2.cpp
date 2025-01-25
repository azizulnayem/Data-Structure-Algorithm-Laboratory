#include<bits/stdc++.h>

using namespace std;

int profit(int Num[])
{
    int profit = 0;
    int price = Num[0];

    int n = sizeof(Num)/sizeof(int);
    for (int i = 1; i < n; i++)
    {
        if (Num[i] < price)
        {
            price = Num[i];
        }
        else
        {
            profit = max(profit, Num[i] - price);
        }
    }
    return profit;
}

int main()
{
    int Num[] = {1, 7, 5, 3, 6, 4};
    cout  << profit(Num) << endl;
    return 0;
}
