
int solve(int i, int j, int k) {
    if ((i / 10 + i % 10 + j / 10 + j % 10) <= k) return 1;
    return 0;
}

void so(int i, int j, int m, int n, int (*v)[105], int *sum, int k) {
    if (i < 0 || j < 0 || i  >= m || j >= n || v[i][j] || !(solve(i, j, k))) return ;
    v[i][j] = 1;
    (*sum)++;
    so(i + 1, j, m, n, v, sum, k);
    so(i - 1, j, m, n, v, sum, k);
    so(i, j - 1, m, n, v, sum, k);
    so(i, j + 1, m, n, v, sum, k);
}


int movingCount(int m, int n, int k) {
    int sum = 0;
    int v[105][105] = {0};
    so(0, 0, m, n, v, &sum, k);
    return sum;
}
