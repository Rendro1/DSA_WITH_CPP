// create a binary tree
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};

node *buildTree(node *root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for insert in left of: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for insert in right : "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// Traversal Technique->
void levelOrderTraversal(node *root){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 tree node
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
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

void Inorder(node *root){
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void preOrder(node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 tree node
    // creating a tree->
    root = buildTree(root);

    //level order traversal
    cout<<"Printing the level order traversal->"<<endl;
    levelOrderTraversal(root);
    cout<<"Printing the preOrder traversal->"<<endl;
    preOrder(root);
    cout<<"Printing the Inorder traversal->"<<endl;
    Inorder(root);
    cout<<"Printing the postOrder traversal->"<<endl;
    postOrder(root);
    return 0;
}