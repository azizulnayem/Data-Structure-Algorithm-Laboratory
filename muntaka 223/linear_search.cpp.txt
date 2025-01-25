#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 2;
    int n = 5;
    int result = search(arr, n, x);
   (result == -1)? cout<<n<<" is not present"
                 : cout<<n<<" is at position: "<<" "<<result;
   return 0;
}
