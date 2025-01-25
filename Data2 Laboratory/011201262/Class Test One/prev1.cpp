#include <iostream>
using namespace std;

// Recursive function to check if a bracket sequence is balanced
bool isBracketSequenceBalanced(string bracketSequence, int n, int count = 0)
{
    // Base case: All brackets have been checked
    if (n == 0)
    {
        // If count is zero, all brackets are balanced
        return (count == 0);
    }

    // If current bracket is opening, increment the count
    if (bracketSequence[n - 1] == '(')
        return isBracketSequenceBalanced(bracketSequence, n - 1, count + 1);

    // If current bracket is closing, decrement the count
    if (bracketSequence[n - 1] == ')')
        return isBracketSequenceBalanced(bracketSequence, n - 1, count - 1);

    // If any other character is encountered, ignore it and continue
    return isBracketSequenceBalanced(bracketSequence, n - 1, count);
}

int main()
{
    string bracketSequence;
    cout << "Enter a string consisting of brackets: ";
    cin >> bracketSequence;

    int n = bracketSequence.length();
    bool result = isBracketSequenceBalanced(bracketSequence, n);

    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
