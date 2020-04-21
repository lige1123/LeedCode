int numberOfSubarrays(int* nums, int numsSize, int k){
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 5));
    memset(sum, 0, sizeof(int) * (numsSize + 5));
    int p = 0;
    int ans = 0;
    sum[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        p += (nums[i] & 1);
        sum[p]++;
        if (p >= k) ans += sum[p - k];
    }
    return ans;
}
