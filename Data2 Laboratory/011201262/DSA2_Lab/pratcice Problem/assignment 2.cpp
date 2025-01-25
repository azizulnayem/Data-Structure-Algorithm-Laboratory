#include<bits/stdc++.h>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class DoublyLinkedList
{
public:
    Node<T>* head;
    Node<T>* tail;
    int length;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void insertAt(Node<T>* newNode, int index)
    {
        if (index < 0 || index > length)
        {
            throw "Index out of bounds";
        }

        if (index == 0)
        {
            insertAtBeginning(newNode);
        }
        else if (index == length)
        {
            insertAtEnd(newNode);
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            length++;
        }
    }

    void insertAtBeginning(Node<T>* newNode)
    {
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void insertAtEnd(Node<T>* newNode)
    {
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteFrom(int index)
    {
        if (index < 0 || index >= length)
        {
            throw "Index out of bounds";
        }

        if (index == 0)
        {
            deleteFromBeginning();
        }
        else if (index == length - 1)
        {
            deleteFromEnd();
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            length--;
        }
    }

    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout<< "Index out of bounds\n";
        }
        else if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        length--;
    }

    void deleteFromEnd()
    {
        if (tail == NULL)
        {
            cout << "Index out of bounds\n";
        }
        else if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        length--;
    }

    int getLength()
    {
        return length;
    }


    int binarySearch(T key)
    {
        int left = 0;
        int right = length - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            Node<T>* current = getNode(mid);

            if (current->data == key)
            {
                return mid;
            }
            else if (current->data < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

private:
    Node<T>* getNode(int index)
    {
        if (index < 0 || index >= length)
        {
            throw "Index out of bounds";
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current;
    }


};





int main()
{
    DoublyLinkedList<int> list;


    list.insertAtEnd(new Node<int>(1));
    list.insertAtEnd(new Node<int>(2));
    list.insertAtEnd(new Node<int>(3));
    list.insertAtEnd(new Node<int>(4));


    list.insertAtBeginning(new Node<int>(0));


    list.insertAt(new Node<int>(99), 3);


    list.deleteFrom(2);


    cout << "Length of list: " << list.getLength() << endl;


    Node<int>* current = list.head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;


     cout << "Start Binary search part\n";

    ifstream input("input.txt");

    if (!input)
    {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    int k;
    input >> k;

    for (int i = 0; i < k; i++)
    {
        int n;
        input >> n;

        DoublyLinkedList<int> list1;

        for (int j = 0; j < n; j++)
        {
            int x;
            input >> x;
            list1.insertAtEnd(new Node<int>(x));
        }

        int key;
        input >> key;

        int result = list1.binarySearch(key);

        if (result != -1)
        {
            cout << result << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    input.close();

    return 0;
}
