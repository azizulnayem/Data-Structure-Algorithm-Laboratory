#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int x, y;
    cout << "Enter Two Number : "<<endl;
    cin >> x >> y;

    cout << gcd(x, y) << endl;

    return 0;
}

