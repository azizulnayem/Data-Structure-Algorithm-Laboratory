#include <iostream>

class CircularQueue {
private:
    int front;
    int rear;
    int capacity;
    int* data;

public:
    CircularQueue(int size);
    ~CircularQueue();

    void enqueue(int elem);
    int dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
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
        return -1; // You can choose any error code to indicate an empty queue.
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
        return -1; // You can choose any error code to indicate an empty queue.
    }
    return data[front];
}

int CircularQueue::size() {
    if (isEmpty()) {
        return 0;
    }
    return (rear >= front) ? (rear - front + 1) : (capacity - front + rear + 1);
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

bool CircularQueue::isFull() {
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

int main() {
    CircularQueue queue(5);

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
