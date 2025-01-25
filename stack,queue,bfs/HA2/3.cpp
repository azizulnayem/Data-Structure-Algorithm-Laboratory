#include <iostream>

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
        return -1; // You can choose any error code to indicate an empty queue.
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
        return -1; // You can choose any error code to indicate an empty queue.
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

int main() {
    Queue queue(5);

    queue.enqueue(30);
    queue.enqueue(10);
    queue.enqueue(50);
    queue.enqueue(20);

    std::cout << "Queue after enqueuing: ";
    queue.display();

    int dequeuedElement = queue.dequeue();
    std::cout << "Dequeued element: " << dequeuedElement << std::endl;

    std::cout << "Queue after dequeuing: ";
    queue.display();

    int frontElement = queue.peek();
    std::cout << "Front element: " << frontElement << std::endl;

    std::cout << "Is the Queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
