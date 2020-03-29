int lastRemaining(int n, int m){
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = (s + m) % i;
    }
    return s;
}
