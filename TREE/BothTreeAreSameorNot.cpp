#include<bits/stdc++.h>
using namespace std;

bool isSameTree(Node *root1,Node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    } 
    if(root1!=NULL && root2==NULL){
        return false;
    } 
    if(root1==NULL && root2!=NULL){
        return false;
    }
    bool left = isSameTree(root1->left,root2->left); 
    bool right = isSameTree(root1->right,root2->right);
    bool currVal = root1->data == root2->data;
    if(left && right && currVal){
        return true;
    } 
    return false;
}

int main(){
    
    return 0;
} 