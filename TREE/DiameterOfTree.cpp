#include<bits/stdc++.h>
using namespace std;

int Height(Node *node){
    if(node==NULL){
        return 0;
    }
    int left = Height(node->left);
    int right = Height(node->right);
    int ans = max(left,right) +1;
    return ans;
}

int Diameter(Node *root){
    if(root==NULL){
        return 0;
    }
    int dia1 = Diameter(root->left); // Diameter for left sub tree
    int dia2 = Diameter(root->right); // Diameter for Right Sub tree
    int heigh = Height(root->left)+Height(root->right); //max height of left and right subtree
    int ans = max(dia1,max(dia2,heigh));
    return ans; // max of those return
}

int main(){
    
    return 0;
}