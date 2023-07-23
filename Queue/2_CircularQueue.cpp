#include<bits/stdc++.h>
using namespace std;

class CircilarQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    CircilarQueue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enQueue(int data){
        if((front==0 && rear==-1) || ((rear==front-1)%(size-1))){ //checking Queue is full or not
            cout<<"Queue is full..."<<endl;
        }
        else if(front ==-1){ //first element to push
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if(rear==size-1 && front !=0){ // to maintain cyclic nature
            rear =0;
            arr[rear] = data;
        }
        else{
            rear++; // normal flow for push element
            arr[rear] = data;
        }
    }
    void deQueue(){
        if(front == -1){ // to check the Queue is empty
            cout<<"Can't pop coz the the Queue is Empty..."<<endl;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // single element is present
            front = rear = -1;
        }
        else if(front == size-1){ // to maintain cyclic nature
            front = 0;
        }
        else{
            front++; // normal flow for pop element
        }
    }
    bool isEmpty(){
        if(front ==-1){
            return true;
        }
        return false;
    }
    int front_ele_index(){
        return front;
    }
    int rear_ele_index(){
        return rear;
    }
};

int main(){
    CircilarQueue q;
    q.enQueue(6);
    q.enQueue(9);
    q.enQueue(11);
    q.enQueue(13);
    q.enQueue(15);
    
    cout<<q.front_ele_index()<<endl;
    cout<<q.rear_ele_index()<<endl;

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