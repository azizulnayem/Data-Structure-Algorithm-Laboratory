#include<bits/stdc++.h>
#define ERROR -9999
#define SUCESS 9999

using namespace std;

class Queue_Vector{
    private:
        vector<int> queue;
        int front = -1;

    public:
        Queue_Vector(){};

        void enqueue(int x){
            if(front == -1){
                front++;
            }
            queue.push_back(x);
        }

        int dequeue(){
            if(front == -1){
                return ERROR;
            }
            int element = queue[front++];
            return element;
        }

        int peek(){
            if(front == -1){
                return ERROR;
            }
            return queue[front];
        }

        void printQueue(){
            for(int i=front; i<queue.size(); i++){
                cout << queue[i] << endl;
            }
        }

};

class Queue_Array{
    private:
        int *queue;
        int size;
        int front = -1;
        int rear = 0;

    public:
        Queue_Array(int size){
            this->size = size;
            queue = new int[size];
        }

        void enqueue(int x){
            if(rear % size != front) {
                queue[rear % size] = x;
                rear++;
            }
            if(front == -1) front++;
        }

        int dequeue(){
            if(front == -1 || front > rear) return ERROR;
            int element = queue[front % size];
            front++;
            return element;
        }

        int peek(){
            if(front == -1 || front > rear) return ERROR;
            return queue[front % size];
        }

        void printQueue(){
            for(int i=front; i<rear; i++){
                cout << queue[i % size] << endl;
            }
        }

        void printArray(){
            for(int i=0; i<size; i++){
                cout << queue[i % size] << endl;
            }
        }

        void printTrackers(){
            cout << "Front = " << front << " rear = " << rear << endl;
        }
};