#define MAX_LEN (20000)
void recursion(int arr_len, int *arr, int numsSize, int **result, int *returnSize, int **returnColumnSizes, bool *used, int *nums){
    int *next_arr;
    int i, j;
    if (arr_len == numsSize) {
        (*returnColumnSizes)[*returnSize] = arr_len;
        result[*returnSize] = (int *)calloc(arr_len, sizeof(int));
        memcpy(result[*returnSize], arr, sizeof(int) * arr_len);
        ++(*returnSize);
        free(arr);
        return;
    }
    for (i = 0; i < numsSize; ++i) {
        if (used[i] == true)
            continue;
	used[i] = true;
        next_arr = (int *)calloc(numsSize, sizeof(int));
        memcpy(next_arr, arr, numsSize * sizeof(int));
        next_arr[arr_len] = nums[i];
        recursion(arr_len + 1, next_arr, numsSize, result, returnSize, returnColumnSizes, used, nums);
	used[i] = false;
    }
    free(arr);
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *) * MAX_LEN);
    int *arr = (int *)calloc(numsSize, sizeof(int));
    bool *used = (bool *)calloc(numsSize, sizeof(bool));
    *returnSize = 0;
    if (numsSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    (*returnColumnSizes) = (int *)calloc(MAX_LEN, sizeof(int));
    recursion(0, arr, numsSize, result, returnSize, returnColumnSizes, used, nums);
    free(used);
    return result;
}
