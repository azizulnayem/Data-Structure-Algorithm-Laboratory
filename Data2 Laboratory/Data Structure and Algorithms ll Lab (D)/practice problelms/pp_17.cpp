//sum of the following series 

//1+2+3+4+5......
// #include<iostream>
// using namespace std;
// int add(int n) {
//     if(n != 0)
//         return n + add(n - 1);
//     return 0;
// }
// int main() {
//     int n;
//     cout << "Enter a positive integer: ";
//     cin >> n;
//     cout << "Sum =  " << add(n);
//     return 0;
// }

//1^2 + 2^2 + 3^2 +.....

//#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

int sum(int n)
{
	if (n == 1)
		return 1;
	else
		return (pow(n, 2) + sum(n - 1));
}

int main()
{
	int n ;
    cin>>n;
	cout << sum(n);

	return 0;
}
