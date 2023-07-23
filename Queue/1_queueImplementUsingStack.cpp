#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(){
        size = 10000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enQueue(int data){
        if(rear == size){
            cout<<"Queue is full..."<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    void deQueue(){
        if(front == rear){
            cout<<"Can't pop coz the the Queue is Empty..."<<endl;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }
    int front_ele(){
        if(front == rear){
            return -1;
        }
        return arr[front]; 
    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        return false;
    }

};

int main(){
    Queue q;
    q.enQueue(6);
    q.enQueue(9);
    q.enQueue(11);
    q.enQueue(13);
    q.enQueue(15);
    cout<<q.front_ele()<<endl;
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}