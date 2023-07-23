#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next !=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for->"<<val<<endl;
    }
};

void insertNode(Node* &tail,int ele,int d){
    //Asuming the element is present in the list->

    //if empty list->
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    // for non empty list->
    else{
        Node* curr = tail;
        while (curr->data != ele)
        {
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
        
    }
}

void print(Node*tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    // cout<<endl;
}
int main(){
    Node* tail = NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,6);
    insertNode(tail,6,8);
    insertNode(tail,8,9);
    print(tail);
    return 0;
}