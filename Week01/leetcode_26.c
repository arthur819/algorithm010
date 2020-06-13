

/*
 * 双指针法, O(n)
 */
int removeDuplicates(int* nums, int numsSize){
	int iterator = 0, next_position = 1, ret = 1;
	if (!nums || !numsSize)
		return 0;
	for (; iterator < numsSize - 1; ++iterator) {
		if (nums[iterator] != nums[iterator + 1]) {
			nums[next_position++] = nums[iterator + 1];
			++ret;
		}
	}
	return ret;
}
