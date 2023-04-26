int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        int bin[32], len = 0;
      
        while (n > 0) {
            bin[len++] = n % 2;
            n /= 2;
        }
        int max = 1, cur = 1;

        for (int j = len - 1; j > 0; j--) {
            if (bin[j] != bin[j - 1]) cur++;
            else cur = 1;
            if (cur > max) max = cur;
        }
        printf("case #%d:\n%d\n", i, max);
    }
    return 0;
}