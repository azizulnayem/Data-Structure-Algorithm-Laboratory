#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove the '(' from stack
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
double evaluatePostfix(const string& postfix) {
    stack<double> operandStack;

    for (char c : postfix) {
        if (isalnum(c)) {
            operandStack.push(c - '0'); // Convert character digit to integer
        } else if (isOperator(c)) {
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+': operandStack.push(operand1 + operand2); break;
                case '-': operandStack.push(operand1 - operand2); break;
                case '*': operandStack.push(operand1 * operand2); break;
                case '/': operandStack.push(operand1 / operand2); break;
            }
        }
    }

    return operandStack.top();
}


// Function to check balanced parentheses in the expression
bool areParenthesesBalanced(const string& expression) {
    stack<char> parenStack;

    for (char c : expression) {
        if (c == '(') {
            parenStack.push(c);
        } else if (c == ')') {
            if (parenStack.empty() || parenStack.top() != '(') {
                return false;
            }
            parenStack.pop();
        }
    }

    return parenStack.empty();
}

int main() {
    string infixExpression = "(A + B) * C - D / E";

    // Convert to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate postfix expression
    double result = evaluatePostfix(postfixExpression);
    cout << "Postfix evaluation result: " << result << endl;

    // Check balanced parentheses
    bool balanced = areParenthesesBalanced(infixExpression);
    cout << "Parentheses are " << (balanced ? "balanced" : "not balanced") << endl;

    return 0;
}
