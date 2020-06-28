#define MAX_LEN (20000)
#define digit2num(digit)   (((digit) > 0x31 && (digit) < 0x3a) ? ((digit) - 0x30) : -1)
void init_map(char **map){
    map[0] = "";
    map[1] = "";
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";
}
void generate(int str_len, char *str, char *digits, char **map, int *returnSize, char **result){
    int j, num = -1;
    int phone_num_len = strlen(digits);
    if (str_len == phone_num_len) {
        result[*returnSize] = (char *)calloc(phone_num_len + 1, sizeof(char));
        strcpy(result[(*returnSize)++], str);
        return;
    }
    num = digit2num(digits[str_len]);
    for (j = 0; j < strlen(map[num]); ++j) {
        str[str_len] = map[num][j];
        generate(str_len + 1, str, digits, map, returnSize, result);
    }
}
char ** letterCombinations(char *digits, int *returnSize){
    char *map[10];
    int len = strlen(digits);
    char *str = (char *)calloc(len + 1, sizeof(char));
    char **result = (char **)calloc(MAX_LEN, sizeof(char *));
    *returnSize = 0;
    if (!len)
        return NULL;
    init_map(map);
    generate(0, str, digits, map, returnSize, result);
    free(str);
    return result;
}
