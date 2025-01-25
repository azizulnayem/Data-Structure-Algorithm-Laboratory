#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value, weight;
    Item(int value, int weight)
        : value(value), weight(weight)
    {
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(struct Item arr[],
                          int sackWeight, int numberOfItems)
{

    sort(arr, arr + numberOfItems, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < numberOfItems; i++)
    {

        if (curWeight + arr[i].weight <= sackWeight)
        {
            cout<< "taking the Item of weight :" << arr[i].weight << endl ;
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            double remain = sackWeight - curWeight;
            double fraction = remain/ arr[i].weight;
            finalvalue += arr[i].value * fraction;
            cout<< "taking the Item number :" << arr[i].weight << " of fraction :" << fraction << endl ;
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int Weight = 60;
    Item arr[] = { { 100, 10 },
        { 2, 40 },
        { 100, 20 },
        { 10, 24 }
    };

    int numberOfItems = sizeof(arr) / sizeof(arr[0]);
    cout << endl << "Maximum profit earned = "
         << fractionalKnapsack(arr, Weight, numberOfItems);
    return 0;
}
