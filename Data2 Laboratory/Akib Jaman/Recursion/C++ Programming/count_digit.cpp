#include <bits/stdc++.h>
using namespace std;

int count_digit(int n,int count)
{
    
    if(n>0)
    {
        count++;
        count_digit(n/10,count++);
    }
    else
    {
        return count;
    }
}

int main()
{
    int n,count=0;

    cin >> n;
    cout << count_digit(n,count);

    return 0;
}