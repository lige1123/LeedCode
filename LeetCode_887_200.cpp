int dp[105][10005];

int superEggDrop(int K, int N){
    if (K == 1) return N;
    if (N == 0) return 0;
    if (dp[K][N]) return dp[K][N];
    int ans = N, s  = 1, h = N + 1;
    while (s < h) {
        int i = s + (h - s) / 2;
        int l = superEggDrop(K - 1, i - 1); //增
        int r = superEggDrop(K, N - i); //减
        ans = fmin(ans, fmax(l, r) + 1);
        if (l < r) {
            s = i + 1;
        } else if (l > r) {
            h = i;
        } else break;
    }
    return dp[K][N] = ans;
}
