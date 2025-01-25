#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool CheckOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

bool CheckingLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool CheckingDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int precedence(char opt) {
    if (opt == '+' || opt == '-')
    {
        return 1;
    }
    if (opt == '*' || opt == '/')
    {
       return 2;
    }
    if (opt == '%' || opt == '^')
    {
        return 3;
    }
    return 0;
}

string infixToPostfix(const string& infix_expression) {
    stack<char> Stack;
    string postfix_expression;

    for (char c : infix_expression)
    {
        if (CheckingLetter(c) || CheckingDigit(c))
        {
            postfix_expression = postfix_expression + c;
        }
        else if (c == '(')
        {
            Stack.push(c);
        }
        else if (c == ')')
        {
            while (!Stack.empty() && Stack.top() != '(')
            {
                postfix_expression = postfix_expression + Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }
        else if (CheckOperator(c))
        {
            while (!Stack.empty() && precedence(Stack.top()) >= precedence(c))
            {
                postfix_expression = postfix_expression + Stack.top();
                Stack.pop();
            }
            Stack.push(c);
        }
    }
    while (!Stack.empty())
    {
        postfix_expression = postfix_expression + Stack.top();
        Stack.pop();
    }
    return postfix_expression;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "\nInfix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
