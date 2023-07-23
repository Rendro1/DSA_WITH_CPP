    vector<int>v;
    void Inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        Inorder(root->left);
        v.push_back(root->val);
        Inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        Inorder(root); // using inorder to get element in sorted order
        int i = 0;
        int j = v.size()-1;
        int sum=0;
        while(i<j){ // using two pointer to calculate sum so TC= O(n) ans SC=O(n);
            sum = v[i]+v[j];
            if(sum<k){
                i++;
            }
            else if(sum>k){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
    }