class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int c = max(b, a + nums[i]);
            a = b;
            b = c;;
        }
        return b;
    }
};
