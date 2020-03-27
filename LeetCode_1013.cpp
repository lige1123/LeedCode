bool canThreePartsEqualSum(int* A, int ASize) {
 //   if (ASize == 0 || A == NULL) return false;
    int sum = 0, s = 0, ans = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3) return false;
    sum /= 3;
    for (int i = 0; i < ASize; i++) {
        ans += A[i];
        if (sum == ans) {
            s++;
            ans = 0;
        }
        if (s == 3) return true;
    }
    return false;
}
