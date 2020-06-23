void reverse(struct TreeNode *root){
    struct TreeNode *tmp;
    if (!root)
        return;
    
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    reverse(root->left);
    reverse(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    reverse(root);
    return root;
}
