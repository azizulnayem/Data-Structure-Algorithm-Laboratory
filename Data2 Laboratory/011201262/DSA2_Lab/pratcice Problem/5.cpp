#include<bits/stdc++.h>
using namespace std;

int CountSum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n%10+CountSum(n/10);
}
int main()
{

    int n;
    cin >>n;
    cout << "Count the number of digits of an integer : "<<CountSum(n)<<endl;

return 0;
}
