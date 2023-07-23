void pred(Node*root,Node* &p,int k){
    
    if(!root)
    return;
    
    pred(root->left,p,k);
    
    if(root->key<k)
        p=root;
    
    pred(root->right,p,k);
    
}

void succ(Node*root,Node*& s,int k){
    
    if(!root)
    return;
    
    succ(root->right,s,k);
    
    if(root->key>k)
        s=root;
    
    succ(root->left,s,k);
    
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

 pred(root,pre,key);
  succ(root,suc,key);

}