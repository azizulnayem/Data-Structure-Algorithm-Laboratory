#include<iostream>
#include<stack>
#include<string>

bool isValidExpression(const std::string& expression) {
    std::stack<char> brackets;
    for (char c : expression) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                    if (brackets.empty()) {
                        return false;
            }
            char openBracket = brackets.top();
            brackets.pop();
            if ((c == ')' && openBracket != '(') ||(c == '}' && openBracket != '{') ||(c == ']' && openBracket != '['))
                {
                    return false;
                }
            }
        }
        return brackets.empty();
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::cin >> expression;

    if (isValidExpression(expression)) {
            std::cout << "Valid expression.\n";
    }
    else {
            std::cout << "Invalid expression.\n";
    }
    return 0;
}
