#include<bits/stdc++.h>

using namespace std;

struct employee
{
    string name;
    int height;
    int age;
};

int main()
{
    int n,temp,temp2;
    string temp1;
    employee emp[100];

    cout<<"Enter total number of employee : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Name : ";
        cin>>emp[i].name;
        cout<<"Height : ";
        cin>>emp[i].height;
        cout<<"Age : ";
        cin>>emp[i].age;
    }

    for(int j=0; j<n; j++)
    {
        temp = emp[j].height;
        for(int i=j+1; i<n; i++)
        {
            if(temp<emp[i].height)
            {
                temp1 = emp[i].name;
                temp2 = emp[i].age;
                temp = emp[i].height;
                emp[i].name = emp[j].name;
                emp[i].age = emp[j].age;
                emp[i].height= emp[j].height;
                emp[j].name = temp1;
                emp[j].age = temp2;
                emp[j].height =temp;
            }
            else if(temp==emp[i].height)
            {
                if(temp2<emp[i].age)
                {
                    temp1 = emp[i].name;
                    temp2 = emp[i].age;
                    temp = emp[i].height;
                    emp[i].name = emp[j].name;
                    emp[i].age = emp[j].age;
                    emp[i].height= emp[j].height;
                    emp[j].name = temp1;
                    emp[j].age = temp2;
                    emp[j].height =temp;
                }
            }
        }
    }

    cout<<endl;
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<emp[i].name<<" "<<emp[i].height<<" "<<emp[i].age<<endl;
    }

    return 0;
}
