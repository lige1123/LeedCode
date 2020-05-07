class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[505][505] = {0};
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    ans = max(ans, (dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1));
                } else {
                    dp[i + 1][j + 1] = 0;
                }
            }
        }
        return ans * ans;
    }
};
