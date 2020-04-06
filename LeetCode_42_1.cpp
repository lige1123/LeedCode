int trap(int* height, int heightSize) {
    int sum = 0;
    int a = 0;
    int b = heightSize -1;
    for (int i = 1; i < heightSize; i++) {
        if (height[a] <= height[i]) {
            for (int j = a + 1; j < i; j++) {
                sum += (height[a] - height[j]);
            }
            a = i;
        }
    }
    for (int i = heightSize - 2; i >= a; i--) {
        if (height[b] <= height[i]) {
            for (int j = b - 1; j > i ; j--) {
                sum += (height[b] - height[j]);
            }
            b = i;
        }
    }
    return sum;
}
