#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructer->
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for data->"<<val<<endl;
    }
};

void print(Node* &head){
    Node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* ptr = head;
    int len=0;
    while(ptr!=NULL){
        len++;
        ptr = ptr->next;
    }
    return len;
}

void insertAtHead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node* ptr = new Node(d);
        head = ptr;
        tail = ptr;
    }
    else{
        Node* ptr = new Node(d);
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* ptr = new Node(d);
        tail = ptr;
        head = ptr;
    }
    else{
        Node* ptr = new Node(d);
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
    

}

void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
    if(pos==1){
        insertAtHead(tail,head,d);
        return;
    }
    Node* ptr = head;
    int cnt =1;
    while(cnt<pos-1){
        ptr = ptr->next;
        cnt++;
    }
    if(ptr->next==NULL){
        insertAtTail(tail,head,d);
        return;
    }
    Node* nodeInsert = new Node(d);
    ptr->next = nodeInsert;
    nodeInsert->next = ptr->next;
    ptr->next->prev = nodeInsert;
    nodeInsert->prev = ptr;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
} 

int main(){
    Node* node1 = new Node(5);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    insertAtHead(tail,head,12);
    print(head);

    // insertAtTail(tail,head,11);
    // print(head);

    insertAtPosition(tail,head,2,100);
    insertAtPosition(tail,head,3,101);
    insertAtPosition(tail,head,4,102);
    insertAtPosition(tail,head,5,104);
    insertAtPosition(tail,head,6,105);
    print(head);
    cout<<"Length of list => "<<getLength(head)<<endl;

    deleteNode(1,head);
    print(head);
    cout<<"Length of list => "<<getLength(head)<<endl;

    deleteNode(5,head);
    print(head);
    cout<<"Length of list => "<<getLength(head)<<endl;
    
    return 0;
}