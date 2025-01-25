#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    if(c>='0' && c<='9') return true;
    else return false;
}
int main()
{
    int result = 2+3*4+9;
    string postfix;
    cin >> postfix;

    stack< int > myStack;
    for(int i=0; i<postfix.length(); i++)
    {
        char currentCharacter = postfix[i];

        if(isOperand(currentCharacter))
        {
            int currentInteger = currentCharacter-'0';
            myStack.push(currentInteger);
        }
        else
        {
            int rightSide = myStack.top();
            myStack.pop();

            int leftSide = myStack.top();
            myStack.pop();

            if(currentCharacter=='+')
            {
                int res = leftSide+rightSide;
                myStack.push(res);
            }
            else if(currentCharacter=='-')
            {
                int res = leftSide-rightSide;
                myStack.push(res);
            }
            else if(currentCharacter=='*')
            {
                int res = leftSide*rightSide;
                myStack.push(res);
            }
            else if(currentCharacter=='/')
            {
                int res = leftSide/rightSide;
                myStack.push(res);
            }

        }
    }

    cout << ((myStack.top()==result) ? "Valid" : "Invalid") << endl;
    return 0;

}
