int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int *arr = NULL;
	struct TreeNode *stack[50000] = {}, *node = NULL;
	int top = 0;
	*returnSize = 0;
	if (!root)  return arr;
	arr = (int *)malloc(sizeof(int) * 50000);
	stack[top++] = root;
	while (top) {
		node = stack[--top];
		arr[(*returnSize)++] = node->val;
		if (node->right)
			stack[top++] = node->right;
		if (node->left)
			stack[top++] = node->left;
	}
	return arr;
}
