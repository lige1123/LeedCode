#define swap(a, b) {a ^= b; b ^= a; a ^= b;}

void reve(char *s, int l, int r) {
    if (l >= r) return;
    while (l < r) {
        swap(s[l], s[r]);
        l++, r--;
    }
}


char * reverseWords(char * s){
    int l = 0, r = strlen(s) - 1;
    reve(s, l, r);
    while (s[0] == ' ') s++;
    int i = 0, j = 0;
    int a = 0;
    char *temp = s;
    while (j <= r) {
        while (s[j] != ' ' && s[j] != 0) {
            j++;
        }
        reve(s, i, j - 1);
        for (int k = 0; k < j - i; k++) {
            *(temp + k) = s[i + k];
        }
        temp = temp +j - i;
        while (s[j] == ' ') j++;
        i = j;
        if (s[j] == 0) {
            *temp = 0;
            break;
        }
        *temp = ' ';
        temp++;
    }
    return s;
}
