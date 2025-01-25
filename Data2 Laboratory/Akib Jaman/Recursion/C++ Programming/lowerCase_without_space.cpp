#include<bits/stdc++.h>

using namespace std;

void conv_into_low(char str[])
{
    for(int i=0; str[i]!=NULL; i++)
    {
        if(str[i]>=65 && str[i]<=92)
        {
            str[i]=str[i]+32;
        }
    }
    cout<<str<<endl;
}
void space(char str[])
{
    for(int i=0; str[i]!=NULL; i++)
    {
        if(str[i]==' ')
        {
            for(int j=i; str[j]!=NULL; j++)
            {
                str[j] = str[j+1];
            }
        }
    }
    cout<<str<<endl;
}

int main()
{
    char str[1000] = "Md mithu Talukdar";;

    cout<<"Old sentence is : "<<str<<endl;

    cout<<"Only lower case sentence is : ";
    conv_into_low(str);

    cout<<"Without any space : ";
    space(str);

    return 0;
}
