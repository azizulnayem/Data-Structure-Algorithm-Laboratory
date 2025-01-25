#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

struct Person
{
  string name;
  //char name[200];
  int age;
  int height;
};


bool compare(Person p1, Person p2)
{
    return p1.height>p2.height;

}

int main(){

  	int number;
  	cin>>number;
    struct Person person[number];

	for(int i=0; i<number; i++){
        cout<< "Person " << i+1 << " Details: " <<endl;
		cout << "Name    : " ;
        cin.ignore();
		getline(cin,person[i].name);
		cout << "Age    : " ;
		cin >> person[i].age;
		cout << "Height : " ;
		cin >> person[i].height;
		cout<< endl;
	}


    cout<< "Displaying the informations : " << endl;
	for(int i=0; i<number; i++){
		cout << person[i].name << " ";
		cout << person[i].age << " ";
		cout << person[i].height << " ";
		cout << endl;
	}

	sort(person, person + (number), compare);

    cout<< "Displaying the  sorted informations : " << endl;
	for(int i=0; i<number; i++){
		cout << person[i].name << " ";
		cout << person[i].age << " ";
		cout << person[i].height << " ";
		cout << endl;
	}

	return 0;
}
