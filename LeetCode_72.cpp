
int min(int a, int b) {
    return a < b ? a : b;
}

int minDistance(char * word1, char * word2){
    int a = strlen(word1);
    int b = strlen(word2);
    printf("%d %d\n", a, b);
    int dp[1005][1005] = {0};
    for (int i = 0; i <= a; i++) {
        dp[i][0] = i;
    } 
    for (int j = 0; j <= b; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    return dp[a][b];
}
