class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        int flag = 0;
        long long N = n;
        if (n < 0) {flag = 1; N = -N;};
        double ans = 1.0;
        while (N) {
            if (N & 1) ans *= x;
            x *= x;
            N >>= 1;
        }
        if (flag) return 1.0 / ans;
        return ans;
    }
};
