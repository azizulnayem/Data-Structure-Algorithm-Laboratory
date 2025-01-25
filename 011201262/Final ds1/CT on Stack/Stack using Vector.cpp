#include<iostream>
#include<vector>
using namespace std;

class Stack
{
private:
    vector< int > myStack;

public:
    Stack()
    {

    }
    void push(int data)
    {
        myStack.push_back(data);
    }
    void pop()
    {
        if(isEmpty()) return;
        else myStack.pop_back();
    }
    int top()
    {
        if(isEmpty()) return -1;
        else
            return myStack.back();
    }
    bool isEmpty()
    {
        if(myStack.size()==0) return true;
        else return false;
    }
};
/// Stack and Queue
int main()
{
    Stack st;


    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    stack< int > myStack;
    queue< int > myQueue;

    return 0;
}
