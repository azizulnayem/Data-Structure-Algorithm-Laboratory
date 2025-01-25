#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    int a = 2, b = 3, c = 4, d = 9;
    int result = 2 + 3 * 4 + 9;

    string postfix;
    cin >> postfix; // use this "234*+9+"

    stack<int> st;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else if (ch == '+')
        {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            int res = operand1 + operand2;
            st.push(res);
        }
        else if (ch == '*')
        {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            int res = operand1 * operand2;
            st.push(res);
        }
    }
    int postfixResult = st.top();
    if (postfixResult == result)
    {
        cout << "The postfix expression is equivalent to the Infix Result: " << postfixResult << endl;
    }
    else
    {
        cout << "The postfix expression is NOT equivalent to the Infix Result." << endl;
    }
    return 0;
}
