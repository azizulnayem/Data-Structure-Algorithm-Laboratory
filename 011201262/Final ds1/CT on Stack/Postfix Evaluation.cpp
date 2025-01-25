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
    int result = 2 + 3 * 4 + 9;
    string postfix; cin >> postfix;
    stack< int > myStack;
    for(int i=0; i<postfix.length(); i++)
    {
        if(isOperand(postfix[i]))
            myStack.push(postfix[i]-'0');
        else
        {
            int rightSide = myStack.top();
            myStack.pop();

            int leftSide = myStack.top();
            myStack.pop();

            switch(postfix[i])
            {
            case '+': myStack.push(leftSide+rightSide); break;
            case '-': myStack.push(leftSide-rightSide); break;
            case '*': myStack.push(leftSide*rightSide); break;
            case '/': myStack.push(leftSide/rightSide); break;
            }
        }
    }

    cout << myStack.top() << endl;
    return 0;
}
