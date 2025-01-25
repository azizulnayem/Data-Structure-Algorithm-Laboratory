#include <iostream>
#include <cstring>

class CircularQueue {
private:
    int front;
    int rear;
    int capacity;
    char* data;

public:
    CircularQueue(int size);
    ~CircularQueue();

    void enqueue(char elem);
    char dequeue();
    char peek();
    int size();
    bool isEmpty();
    bool isFull();
};

CircularQueue::CircularQueue(int size) : front(-1), rear(-1), capacity(size) {
    data = new char[capacity];
}

CircularQueue::~CircularQueue() {
    delete[] data;
}

void CircularQueue::enqueue(char elem) {
    if (isFull()) {
        std::cerr << "Error: Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    data[rear] = elem;
}

char CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty. Cannot dequeue.\n";
        return '\0'; // You can choose any error code to indicate an empty queue.
    }

    char elem = data[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return elem;
}

char CircularQueue::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty. Cannot peek.\n";
        return '\0'; // You can choose any error code to indicate an empty queue.
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

char findFirstNonRepeatingCharacter(const std::string& str) {
    const int MAX_CHAR = 256;
    int charCount[MAX_CHAR] = {0};
    CircularQueue queue(str.length());

    for (char ch : str) {
        charCount[ch]++;
        queue.enqueue(ch);
    }

    while (!queue.isEmpty()) {
        char ch = queue.peek();
        if (charCount[ch] == 1) {
            return ch;
        }
        queue.dequeue();
    }

    return '\0'; // If no non-repeating character found, return null character.
}

int main() {
    std::string input = "hello";
    char firstNonRepeating = findFirstNonRepeatingCharacter(input);

    if (firstNonRepeating != '\0') {
        std::cout << "The first non-repeating character in the string is: " << firstNonRepeating << std::endl;
    } else {
        std::cout << "No non-repeating character found in the string.\n";
    }

    return 0;
}
