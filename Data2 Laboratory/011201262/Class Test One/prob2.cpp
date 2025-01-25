#include <iostream>
using namespace std;

bool isBracketSequenceBalanced(string bracketSequence, int n, int count = 0)
{
    if (n == 0)
    {
        return (count == 0);//brackets balanced
    }


    if (bracketSequence[n - 1] == '(')
        return isBracketSequenceBalanced(bracketSequence, n - 1, count + 1);//increment if opening found

    if (bracketSequence[n - 1] == ')')
        return isBracketSequenceBalanced(bracketSequence, n - 1, count - 1);
    if (count == -1){return false;}
            //decrement if closing found

    return isBracketSequenceBalanced(bracketSequence, n - 1, count);//ignore garbage char
}

int main()
{
    string bracketSequence;
    cin >> bracketSequence;

    int n = bracketSequence.length();
    bool result = isBracketSequenceBalanced(bracketSequence, n);

    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
