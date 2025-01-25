#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int main()
{
    int x, y;
    cout << "Enter Two Number : "<<endl;

    cin >> x >> y;

    cout << "The LCM is: " << lcm(x, y) << endl;
    return 0;
}

