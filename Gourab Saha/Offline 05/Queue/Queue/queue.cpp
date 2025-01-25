// #include<bits/stdc++.h>
#include"queue.h"

int main(){
    Queue_Array q(3);
    q.enqueue(1);
    cout << endl;
    q.enqueue(2);
    q.enqueue(3);
    int l = q.dequeue();
    q.enqueue(4);
    // q.printQueue();
    q.printQueue();
    q.printArray();
    q.printTrackers();
}