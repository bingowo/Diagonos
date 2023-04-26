#include <stdio.h>
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
        int max_l = 1; len = 1;
      
        for (int j = len - 1; j > 0; j--) {
            if (bin[j] != bin[j - 1]) 
                len++; 
            else 
                len = 1; 
            if (len > max_l) 
                max_l = len; 
            if (len == 1 && max_l == 0)
                max_l = 1; //特判只有一个位的情况
        }
        printf("case #%d: %d\n", i, max_l);
    }
    return 0;
}