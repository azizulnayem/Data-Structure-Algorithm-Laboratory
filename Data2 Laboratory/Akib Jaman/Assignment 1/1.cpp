#include<bits/stdc++.h>
using namespace std;

void input(int number[],int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>number[i];
    }
}

int min_number(int number[], int n)
{
    int temp;
    temp = number[0];
    for(int i=1; i<n; i++)
    {
        if(temp<number[i])
        {
            temp = number[i];
        }
    }
    return temp;
}

int maximum(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int maximum_subarray(int num[], int low, int high)
{
    if (high<=low)
    {
        return num[low];
    }
    int mid = low+((high-low)/2);

    int left_max,sum = 0;
    left_max = INT_MIN;

    for (int i = mid; i >= low; i--)
    {
        sum += num[i];
        if (sum > left_max)
        {
            left_max = sum;
        }
    }

    int right_max;
    sum = 0;
    right_max = INT_MIN;
    for (int i = mid+1; i<=high; i++)
    {
        sum += num[i];
        if (sum > right_max)
        {
            right_max = sum;
        }
    }

    int max_left_right,left,right,both_site,result;

    left = maximum_subarray(num,low,mid);
    right = maximum_subarray(num,mid+1,high);
    max_left_right = maximum(left,right);
    both_site = left_max+right_max;
    result = maximum(max_left_right,both_site);
    return result;
}

int main()
{
    int n,number[100];
    n = 9;

    input(number,n);
    cout<<maximum_subarray(number,0,n-1);

    return 0;
}
