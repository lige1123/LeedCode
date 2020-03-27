

void sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j +1] ^= arr[j];
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
            }
        }
    }
}


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a %b);
}



bool hasGroupsSizeX(int* deck, int deckSize){
    sort(deck, deckSize);
  //  int s = deck[0];
    int p = 1, q = 0;
    for (int i = 1;i < deckSize; i++) {
    //    printf("%d\n", deck[i]);
        if (deck[i] == deck[i - 1]) {
            p++;
        } else {
            //printf("%d\n", p);
            q = gcd(q, p);
            p = 1;
        }
    }
    q = gcd(p, q);
    return q >= 2;
}
