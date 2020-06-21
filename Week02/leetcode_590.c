int* postorder(struct Node* root, int* returnSize) {
	int *arr = NULL;
	struct Node *stack1[50000] = {}, *stack2[50000] = {}, *node = NULL;
	int top1 = 0, top2 = 0, child_cnt = 0;
	*returnSize = 0;
	if (!root)  return NULL;
	arr = (int *)malloc(sizeof(int) * 50000);
	stack1[top1++] = root;
	while (top1) {
		node = stack1[--top1];
		stack2[top2++] = node;
		child_cnt = 0;
		while (child_cnt < node->numChildren)
			stack1[top1++] = node->children[child_cnt++];
	}
	while (top2)
		arr[(*returnSize)++] = stack2[--top2]->val;
	return arr;
}
