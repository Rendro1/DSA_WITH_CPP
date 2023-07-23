    void traverseLeft(Node *root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else{
            traverseLeft(root->right,ans);
        }
    }
    
    void traverseLeaf(Node *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    void traverseRight(Node *root,vector<int>&ans){
         if(root==NULL){
             return;
         }
         if(root->left==NULL && root->right==NULL){
             return;
         }
         if(root->right){
             traverseRight(root->right,ans);
         }
         else{
             traverseRight(root->left,ans);
         }
         ans.push_back(root->data);
     }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        //storing first node or root of the tree
        ans.push_back(root->data);
        // Traversing left nodes from root.
        traverseLeft(root->left,ans);
        // Traversing all leaf nodes in left subtree
        traverseLeaf(root->left,ans);
         // Traversing all leaf nodes in right subtree
        traverseLeaf(root->right,ans);
        
        //Traverse right part->
        traverseRight(root->right,ans);
        
        return ans;
        
        
    }