#include<iostream>
#include<bits/stdc++.h>
#include <cctype>
#include<string>
#include<cstring>

using namespace std;

string conv_to_lower(string chk);
string remove_ws (string c);

int main()
{
    string a,b,c;
    getline(cin,a);
    b = conv_to_lower(a);
    c = remove_ws(b);
    cout<<c;
    return 0;
}

string conv_to_lower(string chk)
{
    for(int i=0; i<chk.size(); i++)
    {
        char b = chk[i];
        b = tolower(chk[i]);
        chk[i]=b;
    }
    return chk;
}

string remove_ws (string chk)
{
    chk.erase(remove_if(chk.begin(), chk.end(), ::isspace),chk.end());
    return chk;
}
