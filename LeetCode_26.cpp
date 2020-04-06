int removeDuplicates(int* nums, int numsSize) {
    int a = 0;
    int Size = numsSize;
    for (int i = 1; i < numsSize; i++) {
     //   printf("a = %d i = %d\n", a, i);
        if (nums[i] != nums[a]) {
            nums[a + 1] = nums[i];
       //     printf("a = %d i = %d\n", a, i);
            a++;
        } else {
            Size--;
        }
    }
    return Size;
}
