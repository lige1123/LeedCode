
int dp[105][10005];

int superEggDrop(int K, int N){
    if (K == 1) return dp[K][N] = N;
    if (N == 0) return dp[K][N] = 0;
    if (dp[K][N]) return dp[K][N];
    int ans, s  = 1, h = N;
    while (s + 1 < h) {
        int i = (h + s) / 2;
        int l = superEggDrop(K - 1, i - 1); //增
        int r = superEggDrop(K, N - i); //减
        if (l < r) {
            s = i;
        } else if (l > r) {
            h = i;
        } else {
            s = i;
            h = i;
        }
    }
    ans = 1 + fmin(fmax(superEggDrop(K - 1, s - 1), superEggDrop(K, N - s)), fmax(superEggDrop(K - 1, h - 1), superEggDrop(K, N - h)));
    return dp[K][N] = ans;
}
