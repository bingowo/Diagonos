#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i != T; i++){
        int n, r; scanf("%d%d", &n, &r);
        char res[36] = {0}; int len = 0;
        int flag = 0;
        if (n < 0) flag = 1, n = -n;
        do{
            res[len++] = table[n % r];
            n /= r;
        }while(n);
        if (flag) printf("-");
        for (int j = len - 1; j >= 0; j--)
            printf("%c", res[j]);
        printf("\n");
    }
    return 0;
}