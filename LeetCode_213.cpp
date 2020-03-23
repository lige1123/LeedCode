class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return nums[0];
        int a = 0, b = 0, d = 0;
        for (int i = 0; i < n - 1; i++) {
            int c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        a = 0;
        for (int i = 1; i < n; i++) {
            int e = max(d, a + nums[i]);
            a = d;
            d = e;
        }
        return max(b, d);
    }
};
