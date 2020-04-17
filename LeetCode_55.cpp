class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = 0, s = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[j] > i - j) {
                        s = 1;
                        break;
                    }
                }
                if (s == 0) return false;
                s = 0;
              //  flag = i;
            } else {
                continue;
            }
        }
        return true;
    }
};
