void mapping(int inorder[], map<int, int> &m, int n)
{
    for (int i = 0; i < n; i++)
    {
        m[inorder[i]] = i;
    }
}
Node *solve(int preorder[], int inorder[], int &index, int inorderstart, int inorderend, int n, map<int, int> &m)
{
    if (index >= n || (inorderstart > inorderend))
    {
        return NULL;
    }
    int element = preorder[index++];
    Node *temp = new Node(element);
    int position = m[element];
    temp->left = solve(preorder, inorder, index, inorderstart, position - 1, n, m);
    temp->right = solve(preorder, inorder, index, position + 1, inorderend, n, m);
    return temp;
}
Node *buildTree(int preorder[], int inorder[], int n)
{
    int preorderindex = 0;
    map<int, int> m;
    mapping(inorder, m, n);
    Node *ans = solve(preorder, inorder, preorderindex, 0, n - 1, n, m);
    return ans;
}