class Solution {
public:
    int waysToChange(int n) {
        int v[5] = {1, 5, 10, 25};
        int dp[1000005] = {0};
        dp[0] = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = v[i]; j <= n; j++) {
                //if (j > v[i]) {
                    dp[j] = (dp[j] + dp[j - v[i]]) % 1000000007;
                   // dp[j] %= 1000000007;
                //}
            }
        }
        return dp[n];
    }
};
