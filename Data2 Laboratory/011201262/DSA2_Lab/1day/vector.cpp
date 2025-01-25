#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;

    for(int i=0;i<11;i++)
    {
        v.push_back(i);
    }

     vector<int>::iterator ptr;
    for (ptr = v.begin(); ptr < v.end(); ptr++)
        cout << *ptr << " ";

        cout<<"\n++++++++++++++++++++++++++++++++++++++++++++"<<endl;


    return 0;
}
