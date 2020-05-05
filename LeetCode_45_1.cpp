class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int end = 0, MAXPos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            MAXPos = max(MAXPos, nums[i] + i);
            if (i == end) {
                end = MAXPos;
                step++;
            }
        }
        return step;
    }
};
