// C++ program for activity selection problem.
// The following implementation assumes that the activities
// are already sorted according to their finish time
#include <bits/stdc++.h>
using namespace std;

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
// n --> Total number of activities
// s[] --> An array that contains start time of all activities
// f[] --> An array that contains finish time of all activities
/*void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	cout <<"Following activities are selected "<< endl;

	// The first activity always gets selected
	i = 0;
	cout <<" "<< i;

	// Consider rest of the activities
	for (j = 1; j < n; j++)
	{
	// If this activity has start time greater than or
	// equal to the finish time of previously selected
	// activity, then select it
	if (s[j] >= f[i])
	{
		cout <<" " << j;
		i = j;
	}
	}
}

// driver program to test above function
int main()
{
	int s[] = {1, 3, 0, 5, 8, 5};
	int f[] = {2, 4, 6, 7, 9, 9};
	int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(s, f, n);
	return 0;
}
//this code contributed by shivanisinghss2110
*/

int main(){
	int n;
	cout<<"Give n: ";
	cin>>n;
	vector<vector<int>> v;
	for(int i=0; i<n; i++){
		int start,end;
		cin>>start>>end;
		v.push_back({start,end});
	}
	//sort(v.begin(),v.end(),)

}