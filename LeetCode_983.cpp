class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[370] = {0};
        for (int i = 0; i < days.size(); i++) {
            cout << i << " days " << days[i] << endl;
            dp[days[i]] = -1;
        }
        for (int i = 1; i <= 365; i++) {
            if (dp[i] == 0) {
                dp[i] = dp[i - 1];
            } else if(dp[i] == -1) {
                dp[i] = (dp[i - 1] + costs[0]);
            }
                if (i >= 7) {
                    dp[i] = min(dp[i], dp[i - 7] + costs[1]);
                }
                if(i >= 30) {
                    dp[i] = min(dp[i], dp[i - 30] + costs[2]);
                }
            cout << i << " " << dp[i] << endl;
        }
        return dp[365];
    }
};
