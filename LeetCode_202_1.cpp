class Solution {
    int get_next(int a) {
        int ans = 0;
        while (a) {
            ans += (a % 10) * (a% 10);
            a /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int p = n, q = n;
        while (q != 1) {
            p = get_next(p);
            q = get_next(get_next(q));
            if (p == q) break;
        }
        return q == 1;
    }
};
