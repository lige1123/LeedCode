class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = 0, ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (n < 0) {
                n = nums[i];
            } else {
                n += nums[i];
            }
            ans = max(n, ans);
        }
        return ans;
    }
};
