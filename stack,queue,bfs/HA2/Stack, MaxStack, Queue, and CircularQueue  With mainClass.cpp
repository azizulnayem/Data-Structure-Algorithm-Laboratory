#include <iostream>

// Node class for Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Stack class using Linked List
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
};

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot pop.\n";
        return -1;
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
        return -1;
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

// MaxStack class using Linked List
class MaxStack {
private:
    Node* top;

public:
    MaxStack() : top(nullptr) {}
    ~MaxStack();

    int pop();
    void push(int elem);
    int isEmpty();
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
        return -1;
    }

    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

void MaxStack::push(int elem) {
    int maxSoFar = (isEmpty()) ? elem : std::max(elem, top->data);
    Node* newNode = new Node(elem);
    newNode->next = top;
    top = newNode;
    top->data = maxSoFar;
}

int MaxStack::isEmpty() {
    return (top == nullptr) ? 1 : 0;
}

int MaxStack::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot peek.\n";
        return -1;
    }
    return top->data;
}

int MaxStack::getMax() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot get max.\n";
        return -1;
    }
    return top->data;
}

void MaxStack::display() {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Queue class using Arrays
class Queue {
private:
    int* data;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int elem);
    int dequeue();
    int peek();
    int isEmpty();
    void display();
};

Queue::Queue(int size) : front(0), rear(-1), capacity(size) {
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int elem) {
    if (rear == capacity - 1) {
        std::cerr << "Error: Queue is full. Cannot enqueue.\n";
        return;
    }

    data[++rear] = elem;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty. Cannot dequeue.\n";
        return -1;
    }

    int elem = data[front++];
    if (front > rear) {
        front = 0;
        rear = -1;
    }
    return elem;
}

int Queue::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty. Cannot peek.\n";
        return -1;
    }
    return data[front];
}

int Queue::isEmpty() {
    return (rear == -1);
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    for (int i = front; i <= rear; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// CircularQueue class using Arrays
class CircularQueue {
private:
    int* data;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size);
    ~CircularQueue();

    void enqueue(int elem);
    int dequeue();
    int peek();
    int size();
    int isEmpty();
    int isFull();
    void display();
};

CircularQueue::CircularQueue(int size) : front(-1), rear(-1), capacity(size) {
    data = new int[capacity];
}

CircularQueue::~CircularQueue() {
    delete[] data;
}

void CircularQueue::enqueue(int elem) {
    if (isFull()) {
        std::cerr << "Error: Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % capacity;
    data[rear] = elem;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty. Cannot dequeue.\n";
        return -1;
    }

    int elem = data[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return elem;
}

int CircularQueue::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty. Cannot peek.\n";
        return -1;
    }
    return data[front];
}

int CircularQueue::size() {
    if (isEmpty()) {
        return 0;
    }
    return (rear >= front) ? (rear - front + 1) : (capacity - front + rear + 1);
}

int CircularQueue::isEmpty() {
    return front == -1;
}

int CircularQueue::isFull() {
    return ((rear + 1) % capacity) == front;
}

void CircularQueue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    int current = front;
    while (current != rear) {
        std::cout << data[current] << " ";
        current = (current + 1) % capacity;
    }
    std::cout << data[current] << std::endl;
}

// Main function to demonstrate all functionalities
int main() {
    // Create and test Stack
    Stack stack;
    stack.push(30);
    stack.push(10);
    stack.push(50);
    stack.push(20);

    std::cout << "Stack: ";
    stack.display();
    std::cout << "Top element: " << stack.peek() << std::endl;

    int poppedElement = stack.pop();
    std::cout << "Popped element: " << poppedElement << std::endl;
    std::cout << "Stack after popping: ";
    stack.display();

    // Create and test MaxStack
    MaxStack maxStack;
    maxStack.push(30);
    maxStack.push(10);
    maxStack.push(50);
    maxStack.push(20);

    std::cout << "MaxStack: ";
    maxStack.display();
    std::cout << "Top element: " << maxStack.peek() << std::endl;
    std::cout << "Max element: " << maxStack.getMax() << std::endl;

    // Create and test Queue
    Queue queue(5);
    queue.enqueue(30);
    queue.enqueue(10);
    queue.enqueue(50);
    queue.enqueue(20);

    std::cout << "Queue: ";
    queue.display();
    std::cout << "Front element: " << queue.peek() << std::endl;

    int dequeuedElement = queue.dequeue();
    std::cout << "Dequeued element: " << dequeuedElement << std::endl;
    std::cout << "Queue after dequeuing: ";
    queue.display();

    // Create and test CircularQueue
    CircularQueue circularQueue(5);
    circularQueue.enqueue(30);
    circularQueue.enqueue(10);
    circularQueue.enqueue(50);
    circularQueue.enqueue(20);

    std::cout << "Circular Queue: ";
    circularQueue.display();
    std::cout << "Front element: " << circularQueue.peek() << std::endl;

    int dequeuedCircularElement = circularQueue.dequeue();
    std::cout << "Dequeued element: " << dequeuedCircularElement << std::endl;
    std::cout << "Circular Queue after dequeuing: ";
    circularQueue.display();

    return 0;
}
