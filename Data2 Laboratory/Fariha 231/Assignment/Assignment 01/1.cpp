#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


bool is_prime(int n)
{
    if(n<=1)
    {
        return false;
    }

    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int count_prime(int A[], int n,int len)
{

    if(n<=len-1)
    {
        if(is_prime(A[n]))
        {
            cout<<A[n]<<" ";

            return 1+count_prime(A,n+1,len);

        }
        else return 0+count_prime(A,n+1,len);
    }
    else return 0;

}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int ans=count_prime(A,0,n);
    cout<<"\n#primes="<<ans<<endl;

    return 0;
}
