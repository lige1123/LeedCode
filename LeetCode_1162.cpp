int maxDistance(int** grid, int gridSize, int* gridColSize) {
    int ans = -1;
    int dp[gridSize + 5][gridSize + 5];
    for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                dp[i][j] = (grid[i][j] ? 0 : (1 << 30));
            }
    }
    for (int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j]) continue;
            if(i > 0) 
                dp[i][j] = fmin(dp[i - 1][j] + 1, dp[i][j]);
            if(j > 0) 
                dp[i][j] = fmin(dp[i][j - 1] + 1, dp[i][j]);
        }
    }
    for (int i = gridSize - 1; i >=0; i--) {
        for (int j = gridColSize[i] - 1; j >= 0; j--) {
            if (grid[i][j]) continue;
            if (i < gridSize - 1) 
                dp[i][j] = fmin(dp[i + 1][j] + 1, dp[i][j]);
            if (j < gridSize - 1) 
                dp[i][j] = fmin(dp[i][j + 1] + 1,dp[i][j]);
            ans = fmax(dp[i][j], ans);
        }
    }
    if (ans == (1 << 30)) return -1;
    return ans;
}
