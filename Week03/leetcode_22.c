#define MAX_LEN (20000)

void generate(int left, int right, int max, char *str, int idx, char **res, int *returnSize){
    if (left == max && right == max) {
        res[*returnSize] = (char *)calloc((max << 1) + 1, sizeof(char));
        strcpy(res[(*returnSize)++], str);
        return;
    }
    if (left < max) {
        str[idx] = '(';     // 注意：这里idx不能idx++.....
        generate(left + 1, right, max, str, idx + 1, res, returnSize);
    }
    if (right < left) {
        str[idx] = ')';
        generate(left, right + 1, max, str, idx + 1, res, returnSize);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char *str = (char *)calloc((n << 1) + 1, sizeof(char));
    char **res = (char **)malloc(MAX_LEN * sizeof(char *));
    *returnSize = 0;
    generate(0, 0, n, str, 0, res, returnSize);
//  printf("%d\n", *returnSize);
    return res;
}
