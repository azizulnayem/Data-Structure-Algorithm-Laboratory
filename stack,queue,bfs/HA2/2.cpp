#include <iostream>

class Node {
public:
    int data;
    int maxSoFar; // To store the maximum element up to this node.
    Node* next;

    Node(int value, int max) : data(value), maxSoFar(max), next(nullptr) {}
};

class MaxStack {
private:
    Node* top;

public:
    MaxStack() : top(nullptr) {}
    ~MaxStack();

    int pop();
    void push(int value);
    bool isEmpty();
    int peek();
    int getMax();
    void display();
};

MaxStack::~MaxStack() {
    while (!isEmpty()) {
        pop();
    }
}

int MaxStack::pop() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot pop.\n";
        return -1; // You can choose any error code to indicate an empty stack.
    }

    int poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return poppedValue;
}

void MaxStack::push(int value) {
    if (isEmpty()) {
        top = new Node(value, value);
    } else {
        int maxSoFar = std::max(value, top->maxSoFar);
        Node* newNode = new Node(value, maxSoFar);
        newNode->next = top;
        top = newNode;
    }
}

bool MaxStack::isEmpty() {
    return (top == nullptr);
}

int MaxStack::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot peek.\n";
        return -1; // You can choose any error code to indicate an empty stack.
    }
    return top->data;
}

int MaxStack::getMax() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot get max.\n";
        return -1; // You can choose any error code to indicate an empty stack.
    }
    return top->maxSoFar;
}

void MaxStack::display() {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    MaxStack stack;

    stack.push(30);
    stack.push(10);
    stack.push(50);
    stack.push(20);

    std::cout << "Original Stack: ";
    stack.display();

    int poppedElement = stack.pop();
    std::cout << "Popped element: " << poppedElement << std::endl;

    std::cout << "Stack after popping: ";
    stack.display();

    int topElement = stack.peek();
    std::cout << "Top element: " << topElement << std::endl;

    int maxElement = stack.getMax();
    std::cout << "Max element: " << maxElement << std::endl;

    return 0;
}
