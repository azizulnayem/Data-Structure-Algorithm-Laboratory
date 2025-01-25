#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int d, m, n;
    cin >> d >> m >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int dis = 0;
    int cur = 1;
    for (int i = 0; i < n; i++)
    {

        if (a[i] <=d)
        {
            dis += a[i] - cur;

            //cout << "Dis: " <<dis << endl;
            cur = a[i];
           // cout << "Cur: " <<cur << endl;
            if (dis > m)
            {
                cout << "stop at gas station " << i << "( " << a[i - 1] << " miles )" << endl;

                //  cout<<i<<" "<<a[i-1]<<endl;
                dis = 0;
                i--;
                cur = a[i];
            }
        }
    }
}
