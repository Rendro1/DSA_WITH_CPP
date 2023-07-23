#include<bits/stdc++.h>
using namespace std;

bool isPresent(Node* root,int val){
    if(root->data==val){
        return true;
    }
    if(root==NULL){
        return false;         //it will give O(n) complexity but it should be O(log n);so we have to optimize the solution.
    }
    if(root->data<val){
        return isPresent(root->right,val);
    }
    else{
        return isPresent(root->left,val);
    }
}

// this function is working with O(long n);
bool isPresent(Node* root,int val){
    
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        if(temp->data<val){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return false;
}
int main(){
    
    return 0;
}