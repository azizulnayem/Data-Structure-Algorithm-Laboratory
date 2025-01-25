#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;
    int op=0, flag=0;

    for(int i=0; i<n; i++)
    {
        while(i<n && s1[i]!=s2[i]){
            flag=1;
            i++;
        }

        if(flag){
            op+=1;
        }
        flag=0;
    }
    cout<<op<<endl;
}
