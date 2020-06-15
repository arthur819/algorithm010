void reverse_arr(int *arr, int start, int end){
	int tmp;
	while (start < end) {
		tmp = arr[start];
		arr[start++] = arr[end];
		arr[end--] = tmp;
	}
}

void rotate(int *nums, int numsSize, int k) {
	if (!nums || !numsSize)
		return;
	k = k % numsSize;
	reverse_arr(nums, 0, numsSize - 1);
	reverse_arr(nums, 0, k - 1);
	reverse_arr(nums, k, numsSize - 1);
}
