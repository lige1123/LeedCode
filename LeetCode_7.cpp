int reverse(int x) {
    long long m = 1;
    if (x == (- (m << 31))) return 0;
    int flag = 0;
    long long x_;
    if (x < 0) {
        flag = 1;
        x_ = 0 - x;
    } else {
        x_ = x;
    }
    long long ans = 0;
    while(x_) {
        ans = ans * 10 + (x_ % 10);
        x_ /= 10;
    }
    if (ans >= ((m << 31) - 1)) return 0;
    if (flag) ans = 0 - ans;
    return ans;
}
