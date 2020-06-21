/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_SIZE    (10000)
#define min(a,b)    ((a) > (b) ? (b) : (a))

struct binary_heap {
     int arr[MAX_SIZE];
     int size;
};

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void insert(struct binary_heap *heap, int val){
    int index, i;
    if (!heap || heap->size > MAX_SIZE)
        return;

    index = ++(heap->size) - 1;
    heap->arr[index] = val;
    while (index > 0 && val < heap->arr[(index - 1) >> 1]) {
        heap->arr[index] = heap->arr[(index - 1) >> 1];
        index = (index - 1) >> 1;
    }
    heap->arr[index] = val;
    /* debug usage
    for (i = 0; i < heap->size; ++i)
        printf("%d   ", heap->arr[i]);
    printf("\n");
    */
}

void get_and_pop_min(struct binary_heap *heap, int *result){
    int index = 0, level = 1, i;
    int *arr = NULL;
    if (!heap || !(heap->size)) {
        result = NULL;
        return;
    }
    arr = heap->arr;
    *result = arr[0];
    arr[0] = arr[heap->size - 1];
    --heap->size;
    while ((index << 1) + 1 <= heap->size && (index << 1) + 2 < heap->size && (arr[index] > min(arr[(index << 1) + 1], arr[(index << 1) + 2]))) {
        ++level;
        if (arr[(index << 1) + 1] > arr[(index << 1) + 2]) {
            swap(&arr[index], &arr[(index << 1) + 2]);
            index = (index << 1) + 2;
        } else {
            swap(&arr[index], &arr[(index << 1) + 1]);
            index = (index << 1) + 1;
        }
    }
    /* debug usage
    printf("---->");
    for (i = 0; i < b_min_heap.size; ++i)
        printf("%d   ", b_min_heap.arr[i]);
    printf("\n");
    */
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *array = NULL, i;
    struct binary_heap b_min_heap = {{}, 0};    //定义小顶堆
    *returnSize = 0;
    if (!k || !arr || !arrSize)
        return NULL;
    array = (int *)malloc(k * sizeof(int));

    for (i = 0; i < arrSize; ++i)
        insert(&b_min_heap, arr[i]);
    
    for (i = 0; i < k; ++i)
        get_and_pop_min(&b_min_heap, &array[(*returnSize)++]);

    return array;
}
