#include<bits/stdc++.h>
using namespace std;

void num_swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int selectionSort(int number[], int n)
{
    int c=0;
    for (int i = 0; i < n-1; i++)
    {
        int temp = i;
        for (int j = i+1; j < n; j++)
        {
            if (number[j] < number[temp])
            {
                num_swap(&number[temp], &number[j]);
                c++;

            }

        }
    }
    return c;
}

int main()
{
    int n,number[100];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>number[i];
    }
    cout<<selectionSort(number,n);
}
