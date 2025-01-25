#include <iostream>
using namespace std;

int exceptionalSearch(int arr[], int n, int key, int statusOfTheArray)
{
    if (statusOfTheArray == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
    }
    else if (statusOfTheArray == 1)
    {
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    else if (statusOfTheArray == -1)
    {
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] > key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int statusOfTheArray;
    cin >> statusOfTheArray;
    cout << exceptionalSearch(arr, n, key, statusOfTheArray) << endl;
    return 0;
}
