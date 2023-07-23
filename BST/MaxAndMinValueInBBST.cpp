#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};
Node* InsertIntoBST(Node* root,int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if(root->data<d){
        root->right = InsertIntoBST(root->right,d);
    }
    else{
        root->left = InsertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data !=-1){
        root = InsertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node *root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp==NULL){ // purana level complete ho chuka hai
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); // queue still has some child
            }    
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }    
    }    
}

int Minimum(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
int Maximum(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST->"<<endl;
    takeInput(root);
    cout<<"Printing the BST-"<<endl;
    levelOrderTraversal(root);
    cout<<"Minimum and Maximum Value in BST are-> "<<Minimum(root)<<" "<<Maximum(root)<<endl;
    return 0;
}