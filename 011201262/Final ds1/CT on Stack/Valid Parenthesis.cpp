#include<iostream>
#include<stack>
using namespace std;

bool isOpeningParenthesis(char c)
{
    if(c=='(' || c=='{' || c=='[') return true;
    else return false;
}
int main()
{
    string exp;
    cin >> exp;

    stack< char > myStack;

    /** for(char c : exp)
    {

    }
    **/

    for(int i=0; i<exp.length(); i++)
    {
        char currentCharacter = exp[i];
        if(isOpeningParenthesis(currentCharacter))
            myStack.push(currentCharacter);
        else
        {
            /// time to pop from the stack
            if(myStack.empty()==true)
            {
                cout << "Invalid Parenthesis\n";
                return 0;
            }

            if(currentCharacter==')' && myStack.top()=='(') myStack.pop();
            else if(currentCharacter=='}' && myStack.top()=='{') myStack.pop();
            else if(currentCharacter==']' && myStack.top()=='[') myStack.pop();
            else
            {
                cout << "Invalid Parenthesis\n";
                return 0;
            }
        }

    }




    if(myStack.empty()==true)
        cout << "Valid Parenthesis\n";
    else
        cout << "Invalid Parenthesis\n";

    return 0;
}
