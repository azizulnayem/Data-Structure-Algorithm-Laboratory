#include<bits/stdc++.h>

using namespace std;

struct employee
{
    string name;
    int id;
    int salary;
};

int main()
{
    int n,temp,temp2;
    string temp1;
    employee emp[100];

    cout<<"Enter total number of employee : ";
    cin>>n;

    cout<<"Name : ";
    for(int i=0; i<n; i++)
    {
        cin>>emp[i].name;
    }
    cout<<"ID : ";
    for(int i=0; i<n; i++)
    {
        cin>>emp[i].id;
    }
    cout<<"Salary : ";
    for(int i=0; i<n; i++)
    {
        cin>>emp[i].salary;
    }
    for(int j=0; j<n; j++)
    {
        temp = emp[j].salary;
        for(int i=j+1; i<n; i++)
        {
            if(temp>emp[i].salary)
            {
                temp1 = emp[i].name;
                temp2 = emp[i].id;
                temp = emp[i].salary;
                emp[i].name = emp[j].name;
                emp[i].id = emp[j].id;
                emp[i].salary= emp[j].salary;
                emp[j].name = temp1;
                emp[j].id = temp2;
                emp[j].salary =temp;
            }
            else if(temp==emp[i].salary)
            {
                if(emp[j].id>emp[i].id)
                {
                    temp1 = emp[i].name;
                    temp2 = emp[i].id;
                    temp = emp[i].salary;
                    emp[i].name = emp[j].name;
                    emp[i].id = emp[j].id;
                    emp[i].salary= emp[j].salary;
                    emp[j].name = temp1;
                    emp[j].id = temp2;
                    emp[j].salary =temp;
                }
            }
        }
    }

    cout<<endl;
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<emp[i].name<<" "<<emp[i].salary<<" "<<emp[i].id<<endl;
    }

    return 0;
}
