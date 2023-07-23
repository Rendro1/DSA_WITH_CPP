// // Tree create and traversal ->

// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int data;
//     node *left;
//     node *right;

//     node(int d){
//         this->data = d;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// // Traversal part->

// void LevelOrderTraverse(node *root){
//     queue<node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         node *temp = q.front();
//         q.pop();
//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// node *buildTree(node *root){
//     cout<<"Enter the data : ";
//     cout<<endl;
//     int data;
//     cin>>data;
//     root = new node(data);
//     if(data==-1){
//         return NULL;
//     }
//     cout<<"Enter the left child of :"<<data<<endl;
//     root->left = buildTree(root->left);
//     cout<<"Enter the right child of :"<<data<<endl;
//     root->right = buildTree(root->right);

//     return root;
// }

// int main(){
//     node *root = NULL;
//     root = buildTree(root);
//     cout<<"Level order traversal->"<<endl;
//     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 tree node
//     LevelOrderTraverse(root);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data->";
    cout<<endl;

    int data;
    cin>>data;
    root = new node(data);

    if(data==-1){
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
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
int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<endl;
    cout<<"Level order traversal is->"<<endl;
    levelOrder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    return 0;
}