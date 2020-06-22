int climbStairs(int n){
    int f1 = 1, f2 = 2, tmp, res = 0;
    if (n <= 1) return f1;
    if (n == 2) return f2;
    tmp = n;
    while (tmp >= 3) {
        --tmp;
        res = f1 + f2;
        f1 = f2;
        f2 = res;
    }
    return res;
}
