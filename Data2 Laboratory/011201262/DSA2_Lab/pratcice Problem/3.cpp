#include<bits/stdc++.h>
using namespace std;

int Pow(int x,int y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;
    return x*Pow(x,y-1);

}
int main()
{
    int x,y;
    cin >> x >>y;

    cout << x<<"^"<<y<<" = "<<Pow(x,y)<<endl;



return 0;
}
