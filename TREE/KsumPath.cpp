void solve(TreeNode* root,int &count, int k,vector<int>path){
    //Base case
    if(root==NULL){
        return;
    }
    // storing first values
    path.push_back(root->val);
    // calling left subtree
    solve(root->left,count,k,path);
    //calling right subtree
    solve(root->right,count,k,path);
    //check for k sum is present or not
    int size = path.size();
    long long int sum = 0;
    for(int i=size-1;i>=0;i--){
        sum += path[i];
        if(sum==k){
            count++;
        }
    }
    // poping the last value befor going to another side like this tree when we are going after storing 10 5 3 3 so before going to right we r poping last 3 and going to right ans pushing 2 so now the vector looks like 10 5 3 -2
    path.pop_back();
}
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int count=0;
        solve(root,count,targetSum,path);
        return count;
    }

//        10
//     5     -3
//   3  2      11
// 3  -2  1              --->The tree look like and target sum is k=8;
                            //  count the number of path whose sum is 8.