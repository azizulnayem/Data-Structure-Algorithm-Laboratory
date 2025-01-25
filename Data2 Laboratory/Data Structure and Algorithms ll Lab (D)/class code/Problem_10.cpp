#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;
struct Person
{
    string name;
    int id;
    int salary;
};

bool compare(Person p1, Person p2)
{
    if(p1.salary==p2.salary)
       return p1.id<p2.id;
    else return p1.salary<p2.salary;
}

int main()
{
    int number;
    cout<<"enter a number:  ";
    cin>>number;
    string string_store[number];
    int id_store[number], salary_store[number];
    struct Person person[number];
    cin.ignore();
    for(int i=0; i<number; i++)
    {

        getline(cin,string_store[i]);
        person[i].name=string_store[i];
    }

    for(int i=0; i<number; i++)
    {
        cin>>id_store[i];
        person[i].id=id_store[i];
    }
    for(int i=0; i<number; i++)
    {
        cin>>salary_store[i];
        person[i].salary=salary_store[i];
    }
    cout<<"Displaying the information: "<<endl;
    for(int i=0; i<number; i++)
    {
        cout<< person[i].name <<" " << person[i].id
            <<" " << person[i].salary << endl;
    }
    sort(person, person+number, compare);
    cout<<"Displaying the sorted information: "<<endl;
    for(int i=0; i<number; i++)
    {
        cout<< person[i].name <<" " << person[i].id
            <<" " << person[i].salary << endl;
    }


    return 0;
}


