int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int *arr = NULL;
	struct TreeNode *stack[50000] = {}, *node;
	int top = 0;
	*returnSize = 0;
	if (!root)  return arr;
	arr = malloc(sizeof(int) * 50000);
	node = root;
	while (top || node) {
		while (node) {
			stack[top++] = node;
			node = node->left;
		}
		if (top) {
			node = stack[--top];
			arr[(*returnSize)++] = node->val;
			if (node->right)
				node = node->right;
			else
				node = NULL;
		}
	}
	return arr;
}

