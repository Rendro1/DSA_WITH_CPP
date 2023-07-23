// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }

//     ~Node(){
//         int val = this->data;
//         if(this->next !=NULL){
//             delete next;
//             this->next = NULL;
//         }
//         cout<<"Memory is free for->"<<val<<endl;
//     }
// };

// void InsertAtHead(Node* &head,int data){
//     Node* ptr = new Node(data);
//     ptr->next = head;
//     head = ptr;
// }
// void InsertAtTail(Node* &tail,int data){
//     Node* ptr = new Node(data);
//     tail->next = ptr;
//     tail = tail->next;
//     ptr->next = NULL;
//     tail = ptr;
    
// }
// void InsertAtPos(Node* &head,int pos,int data){
//     Node* ptr = head;
//     int cnt=1;
//     while(cnt!=pos-1){
//         ptr = ptr->next;
//         cnt++;
//     }
//     Node* temp = new Node(data);
//     temp->next = ptr->next;
//     ptr->next=temp;
// }


// void print(Node* &head){
//     Node* ptr = head;
//     while(ptr !=NULL){
//         cout<<ptr->data<<" ";
//         ptr = ptr->next;
//     }
//     cout<<endl;
// }


// int main(){
//     Node* node1 = new Node(2);
//     Node* head = node1;
//     Node* tail = node1;

//     InsertAtHead(head,5);
//     print(head);
//     InsertAtTail(tail,4);
//     print(head);
//     InsertAtPos(head,3,12);
//     print(head);
//     return 0;
// }


// Program of circular Linked list-->
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for data->"<<val;
    }
};

void insertNode(Node* &tail,int ele,int data){
    // if the list is empty so we have to create 1st node-->
    if(tail==NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = tail;
    }
    // if already 1 data is exist in the list then we have to Add up the rest data
    else{
        Node* curr = tail;
        while(curr->data != ele){
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
  
    }
}

void printList(Node* tail){
    Node* ptr= tail;
    do{
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }while(ptr!=tail);
}

int main(){
    Node* tail = NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,6);
    insertNode(tail,6,8);
    insertNode(tail,8,9);
    printList(tail);
    return 0;
}