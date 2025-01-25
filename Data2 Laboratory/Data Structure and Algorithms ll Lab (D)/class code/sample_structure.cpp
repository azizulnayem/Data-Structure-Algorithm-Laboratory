#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Person
{
  string name;
  int age;
  int height;
};
void sortFunction(Person a, Person b){
    //if(a.height!=b.height)
        return a.height>b.height;
}

int main(){

  	int number,a,b;
  	cin>>number;
    struct Person person[number];

	for(int i=0; i<number; i++){
		cout << "Name    : " ;
		cin >> person[i].name;
		cout << "Age    : " ;
		cin >> person[i].age;
		cout << "Height : " ;
		cin >> person[i].height;
		cout<< endl;
	}
	sort(a,b+number,sortFunction);

    cout<< "Displaying the informations : " << endl;
	for(int i=0; i<number; i++){
		cout << person[i].name << " ";
		cout << person[i].age << " ";
		cout << person[i].height << " ";
		cout << endl;
	}
	return 0;
}
