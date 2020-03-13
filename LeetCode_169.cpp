int majorityElement(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[0]) continue;
        int ans = nums[i], sum = 1;
        for (int j = i + 1; j < numsSize; j++) {
            if (ans == nums[j]) {
                sum++;
                nums[i] = nums[0];
            }
        }
        if (sum >= (numsSize + 1) / 2) return ans;
    }
    return 0;
}
