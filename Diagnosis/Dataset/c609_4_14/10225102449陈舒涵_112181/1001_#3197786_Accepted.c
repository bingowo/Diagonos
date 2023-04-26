#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    char s[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int t = 0; t < T; t ++){
        int N, R, r;
        char ans[32];
        scanf("%d %d", &N, &R);
        if (N < 0){
            printf("-");
            N = -N;
        }
        int i = 0;
        while (N > 0){
            r = N % R;
            ans[i] = s[r];
            i ++;
            N /= R;
        }
        for (int j = i - 1; j >= 0; j --){
            printf("%c", ans[j]);
        }
        printf("\n");
    }
    return 0;
}
