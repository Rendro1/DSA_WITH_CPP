 // balance bst or not (height of tree is <=1 hote hobe)
 void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        // traversing inorder to store element in sorted order in vector
    }
    TreeNode* balanceOrNot(int start,int end,vector<int>v){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2; // finding mid to constract root of the tree.
        TreeNode* root = new TreeNode(v[mid]); //constracting root to create a tree

         // checking the left subtree balance or not->
        root->left = balanceOrNot(start,mid-1,v);
         // checking the right subtree balance or not->
        root->right = balanceOrNot(mid+1,end,v);

        // after check done returning root.
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v); // Inorder stored.
        return balanceOrNot(0,v.size()-1,v);
    }

// Approach ->
//     if there is a BST->
//             1 2 3 4 5 6 7
//             so mid = 3 index after traversing inorder.
//             start = 0 ,end = v.size() so 7 here.
//             so constracting bst with the left side element (1,2,3) with the help       of recursion so root->left = balanceOrNot(start,mid-1,v); 0 to mid-1.
//             and constracting bst with the right side element (1,2,3) with the help of recursion root->right = balanceOrNot(mid+1,end,v); mid+1 to end