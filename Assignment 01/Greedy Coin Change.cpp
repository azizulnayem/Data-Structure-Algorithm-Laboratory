#include <iostream>

using namespace std;

void makeChange(int amount) {
    int quarters, dimes, nickels, pennies;
    quarters = amount / 25;
    amount %= 25;

    dimes = amount / 10;
    amount %= 10;

    nickels = amount / 5;
    amount %= 5;

    pennies = amount;

    if (quarters > 0)
        cout << "25 cents --- " << quarters << endl;
    if (dimes > 0)
        cout << "10 cents --- " << dimes << endl;
    if (nickels > 0)
        cout << "5 cents --- " << nickels << endl;
    if (pennies > 0)
        cout << "1 cent --- " << pennies << endl;

    int totalCoins = quarters + dimes + nickels + pennies;
    cout << "Total " << totalCoins << " coins" << endl;
}

int main() {
    int amount;
    cout << "Enter the amount in cents: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Invalid input. Amount must be a non-negative integer." << endl;
        return 1;
    }

    makeChange(amount);

    return 0;
}
