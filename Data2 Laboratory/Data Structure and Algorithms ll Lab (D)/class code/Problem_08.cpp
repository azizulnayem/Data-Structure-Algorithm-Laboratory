#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;

string toggle_machine(string chk);
int main()
{
    string a,b;
    getline(cin,a);
    b = toggle_machine(a);
    cout<<b;
    return 0;
}
string toggle_machine(string chk)
{
    for(int i=0;i<chk.length();i++)
    {
        char b = chk[i];
        if(isupper(b))
            b=tolower(b);
        else
            b=toupper(b);
        chk[i]=b;
    }
    return chk;
}
