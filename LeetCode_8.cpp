int myAtoi(char * str) {
    int flag = 0, s = 0;
    long long num = 0;
    for(int i = 0; str[i]; i++) {
        if (flag == 0 && str[i] == ' ') continue;
        if (flag == 0 && (str[i] == '-' || str[i] == '+')) {
            flag = 1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            flag = 1;
            if (i && str[i - 1] == '-') {
                s = 1;
            }
            num = num * 10 +  (str[i] - '0');
        } else {
            break;
        }
        if (s && (num - 1 >= INT_MAX)) {
            return INT_MIN;
        }
        if ((s == 0) && (num >= INT_MAX)) {
            return INT_MAX;
        }
    }
    if(s) return num * (-1);
    return num;
}
