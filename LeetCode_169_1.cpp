int majorityElement(int* nums, int numsSize) {
    int ans = nums[0], cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == ans) {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt <= 0) {
            ans = nums[i];
            cnt = 1;
        }
    }
    return ans;
}
