#include<bits/stdc++.h>


using namespace std;

struct Student {
  string name ;
  string ID ;

  int marks;


};

bool comp(Student s1,Student s2)
{
    return s1.name<s2.name;
}

int main()
{
   Student st[] = {{"Emon","1",80},{"Sayem","2",90},{"Kibria","3",70},{"Habib","4",85},{"Iram","5",87}};

   int n = sizeof(st)/sizeof(st[0]);

   sort(st,st+n,comp);

   int i;

   for(i =0; i<n; i++)
   {
       cout<< st[i].name << " "<< st[i].ID << " "<<st[i].marks << endl;
   }





    return 0;
}
