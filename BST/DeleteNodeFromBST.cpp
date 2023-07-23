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

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

void levelOrderTraversal(Node *root){
    queue<Node*>
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

Node* DeleteNodeFromBST(Node* root,int val){
    // Base case->
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //For leaf Node or 0 child->
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //For 1 child->
        //left child-->
        if(root->left !=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //Right child-->
        if(root->left ==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //For 2 child->
        if(root->left!=NULL && root->right!=NULL){
            Node* temp = minVal(root->right);
            int mini =  temp -> data;
            root->data = mini;
            root->right = DeleteNodeFromBST(root->right,val);
            return root;
        }

    }
    else if(root->data>val){
        root->left = DeleteNodeFromBST(root->left,val);
        return root;
    }
    else{
       root->right = DeleteNodeFromBST(root->right,val);
       return root; 
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST->"<<endl;
    takeInput(root);
    cout<<endl<<"Enter the value to delete the node->";
    int val;
    cin>>val;
    DeleteNodeFromBST(root,val);
    cout<<endl<<"Printing the BST-"<<endl;
    levelOrderTraversal(root);
    return 0;
}

// 50 20 70 10 30 90 110 -1 for this input check.