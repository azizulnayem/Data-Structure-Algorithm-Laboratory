#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

int performOperation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; // Handle other cases as needed
    }
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> operators;

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(' || operators.empty() || operators.top() == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else { // Operator
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += ' ';
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}


bool isValidParentheses(const string& expression) {
    stack<char> parentheses;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            parentheses.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (parentheses.empty() ||
                (c == ')' && parentheses.top() != '(') ||
                (c == ']' && parentheses.top() != '[') ||
                (c == '}' && parentheses.top() != '{')) {
                return false;
            }
            parentheses.pop();
        }
    }

    return parentheses.empty();
}

int evaluatePostfix(const string& postfix) {
    stack<int> operands;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isOperand(token[0])) {
            operands.push(stoi(token));
        } else {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(performOperation(token[0], a, b));
        }
    }

    return operands.top();
}

int main() {
    stack<int> Stack;

    int choice;
    do {
        cout << "Choose an operation: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Empty" << endl;
        cout << "5. Size" << endl;
        cout << "6. Postfix Evaluation" << endl;
        cout << "7. Infix to Postfix Conversion" << endl;
        cout << "8. Valid Parenthesis Check" << endl;
        cout << "9. View Items in Stack" << endl; // New case
        cout << "10. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                Stack.push(value);
                break;
            }
            case 2: {
                if (!Stack.empty()) {
                    Stack.pop();
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            }
             case 3: {
                if (!Stack.empty()) {
                    cout << "Top element: " << Stack.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            }
            case 4: {
                if (Stack.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            }
            case 5: {
                cout << "Size of stack: " << Stack.size() << endl;
                break;
            }
            case 6: {
                string postfixExpression;
                cout << "Enter postfix expression: ";
                cin.ignore(); // Clear the newline character from previous input
                getline(cin, postfixExpression);
                int result = evaluatePostfix(postfixExpression);
                cout << "Result: " << result << endl;
                break;
            }
            case 7: {
                string infixExpression, postfixExpression;
                cout << "Enter infix expression: ";
                cin.ignore(); // Clear the newline character from previous input
                getline(cin, infixExpression);
                postfixExpression = infixToPostfix(infixExpression);
                cout << "Postfix expression: " << postfixExpression << endl;
                break;
            }
            case 8: {
                string expression;
                cout << "Enter expression to check: ";
                cin.ignore(); // Clear the newline character from previous input
                getline(cin, expression);
                if (isValidParentheses(expression)) {
                    cout << "Parentheses are balanced." << endl;
                } else {
                    cout << "Parentheses are not balanced." << endl;
                }
                break;
            }
            case 9: {
                if (Stack.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Items in the stack: ";
                    stack<int> tempStack = Stack;
                    while (!tempStack.empty()) {
                        cout << tempStack.top() << " ";
                        tempStack.pop();
                    }
                    cout << endl;
                }
                break;
            }
            case 10: {
                cout << "Exiting." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please choose again." << endl;
                break;
            }
        }
    } while (choice != 10);

    return 0;
}
