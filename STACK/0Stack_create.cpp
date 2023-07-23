#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele){
        if(size-top > 1){
            top++;
            arr[top] = ele;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }

    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            cout<<"Stack is not empty"<<endl;
            return false;
        }
    }
};
 
int main(){

    Stack s(5);

    s.push(22);
    s.push(32);
    s.push(42);
    s.push(52);
    s.push(62);

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    return 0;
}