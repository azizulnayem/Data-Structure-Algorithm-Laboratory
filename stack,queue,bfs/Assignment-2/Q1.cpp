#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    ~Stack();

    int pop();
    void push(int elem);
    int isEmpty();
    int peek();
    void display();
    void sort();
};

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot pop.\n";
        return -1; // You can choose any error code to indicate an empty stack.
    }

    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

void Stack::push(int elem) {
    Node* newNode = new Node(elem);
    newNode->next = top;
    top = newNode;
}

int Stack::isEmpty() {
    return (top == nullptr) ? 1 : 0;
}

int Stack::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot peek.\n";
        return -1; // You can choose any error code to indicate an empty stack.
    }
    return top->data;
}

void Stack::display() {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Stack::sort() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot sort.\n";
        return;
    }

    Stack tempStack;
    while (!isEmpty()) {
        int temp = pop();
        while (!tempStack.isEmpty() && tempStack.peek() > temp) {
            push(tempStack.pop());
        }
        tempStack.push(temp);
    }

    while (!tempStack.isEmpty()) {
        push(tempStack.pop());
    }
}

int main() {
    Stack stack;

    stack.push(30);
    stack.push(10);
    stack.push(50);
    stack.push(20);

    std::cout << "Original Stack: ";
    stack.display();

    stack.sort();

    std::cout << "Sorted Stack: ";
    stack.display();

    return 0;
}
