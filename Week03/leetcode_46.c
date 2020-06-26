#define MAX_LEN (20000)
void recursion(int arr_len, int *arr, int numsSize, int **result, int *returnSize, int **returnColumnSizes, int *used, int *nums){
    int *next_arr, *next_used;
    int i, j;
    if (arr_len == numsSize) {
        (*returnColumnSizes)[*returnSize] = arr_len;
        result[*returnSize] = (int *)calloc(arr_len, sizeof(int));
        memcpy(result[*returnSize], arr, sizeof(int) * arr_len);
        ++(*returnSize);
        free(arr);
        free(used);
        return;
    }
    for (i = 0; i < numsSize; ++i) {
        if (used[i] == 1)
            continue;
        next_used = (int *)calloc(numsSize, sizeof(int)); 
        next_arr = (int *)calloc(numsSize, sizeof(int));
        memcpy(next_used, used, numsSize * sizeof(int));
        next_used[i] = 1;
        memcpy(next_arr, arr, numsSize * sizeof(int));
        next_arr[arr_len] = nums[i];
        recursion(arr_len + 1, next_arr, numsSize, result, returnSize, returnColumnSizes, next_used, nums);
    }
    free(arr);
    free(used);
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *) * MAX_LEN);
    int *arr = (int *)calloc(numsSize, sizeof(int));
    int *used = (int *)calloc(numsSize, sizeof(int));
    *returnSize = 0;
    if (numsSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    (*returnColumnSizes) = (int *)calloc(MAX_LEN, sizeof(int));
    recursion(0, arr, numsSize, result, returnSize, returnColumnSizes, used, nums);
    return result;
}
