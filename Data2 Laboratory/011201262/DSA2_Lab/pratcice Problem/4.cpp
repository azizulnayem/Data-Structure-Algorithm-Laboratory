#include<bits/stdc++.h>
using namespace std;

int Count(int n)
{
    if(n==0)
    {
        return 0;
    }
    return 1+Count(n/10);
}
int main()
{

    int n;
    cin >>n;
    cout << "Count the number of digits of an integer : "<<Count(n)<<endl;

return 0;
}
