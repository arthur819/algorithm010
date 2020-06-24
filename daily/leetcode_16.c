#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define MAX_INT (0x7fffffff)

void Qsort(int *a, int low, int high){
    if (low>=high)
        return;
    //printf("start:%d  end:%d\n",low,high);
    int first = low;
    int last = high;
    int key = a[low];
    while (first < last) {
        while(first < last && a[last] >= key)
            --last;
        a[first] = a[last];
        while(first < last && a[first] <= key)
            ++first;
        a[last] = a[first];
    }
    a[first] = key;
    Qsort(a, low, first - 1);
    Qsort(a, first + 1, high);
}

int threeSumClosest(int* nums, int numsSize, int target){
        int res, i, head, rear, delta, min_delta = MAX_INT;
        Qsort(nums, 0, numsSize - 1);
        /* debug usage
        for (i = 0; i < numsSize; ++i)
            printf("-->%d\t", nums[i]);
        printf("\n");
        */
        res = nums[0] + nums[1] + nums[numsSize - 1];
        for (i = 0; i <= numsSize - 3; ++i) {
                head = i + 1;
                rear = numsSize - 1;
                while (head <= numsSize - 2 && rear > head) {
                        delta = target - nums[i] - nums[head] - nums[rear];
                        if (!delta)
                            return target;
                        if (abs(delta) < min_delta) {
                            res = nums[i] + nums[head] + nums[rear];
                            min_delta = abs(delta);
                        }
                        if (delta > 0)
                            ++head;
                        else if (delta < 0)
                            --rear;
                }
        }
        return res;
}
