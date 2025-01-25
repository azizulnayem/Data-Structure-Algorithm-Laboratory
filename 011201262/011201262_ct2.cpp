#include <iostream>
#include <stack>
using namespace std;

stack<char> initDocument()
{
    stack<char> document;
    return document;
}

void insertText(stack<char> &document, char c)
{
    document.push(c);
}

void undo(stack<char> &document, int count)
{
    while (count > 0 && !document.empty())
    {
        document.pop();
        count--;
    }
}

void showDocument(stack<char> &document)
{
    stack<char> character;
    while (!document.empty())
    {
        character.push(document.top());
        document.pop();
    }

    while (!character.empty())
    {
        cout << character.top();
        document.push(character.top());
        character.pop();
    }
    cout << endl;
}

int main() {
    stack<char> document = initDocument();
    insertText(document, 'u');
    insertText(document, 'n');
    insertText(document, 'i');
    insertText(document, 't');
    showDocument(document); // Output: unit
    insertText(document, '4');
    insertText(document, '0');
    insertText(document, '4');
    showDocument(document); // Output: unit404
    undo(document, 2);
    insertText(document,'9');
    showDocument(document); // Output: unit49
    insertText(document, 'b');
    undo(document,5);
    insertText(document,'d');
    insertText(document,'s');
    showDocument(document); // Output: unds
    return 0;
}

