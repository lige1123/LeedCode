int minimumLengthEncoding(char ** words, int wordsSize) {
   int flag = 0, size = 0;
   char **Newwords = (char **)malloc(sizeof(char *) * wordsSize);
   int n = 0;
   for (int i = 0; i < wordsSize; i++) {
       int j = 0;
    //    flag = 0;
       for (j = 0; j < size; j++) {
           flag = 1;
           int k1 = strlen(words[i]), k2 = strlen(Newwords[j]);
           while (k1 >= 0 && k2 >= 0) {
               if (words[i][k1--] != Newwords[j][k2--]) {
                   flag = 0;
                   break;
               }
           }
           //if (flag) continue;
           if (flag && k1 >= 0) {
               Newwords[j] = words[i];
               n += (k1 - k2);
           }
           if (flag) {
               break;
           }
       }
       if (!flag) {
           n += (strlen(words[i]) + 1);
           Newwords[size++] = words[i];
       }
   }
   return n;
}
