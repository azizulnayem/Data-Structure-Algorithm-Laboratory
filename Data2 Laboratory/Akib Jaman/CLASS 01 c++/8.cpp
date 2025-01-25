#include<bits/stdc++.h>

using namespace std;

void conv_into_toggle(char str[])
{
    for(int i=0; str[i]!=NULL; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
        else if(str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;
        }
    }
    cout<<str<<endl;
}

int main()
{
    char str[1000] = "Md mithu Talukdar";;

    cout<<"Old sentence is : "<<str<<endl;

    cout<<"After toggle sentence is : ";
    conv_into_toggle(str);

    return 0;
}
