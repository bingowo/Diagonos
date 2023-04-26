#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    char table[] = "01235456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i != T; i++){
        int n, r; scanf("%d%d", &n, &r);
        char res[36] = {0}; int len = 0, flag = 0;
        if (n < 0) n = -n, flag = 1;
        do{
            res[len++] = table[n % r];
            n /= r;
        }while(n);
        if (flag) printf("-");
        for (int i = len - 1; i >= 0; i--)
            printf("%c", res[i]);
        printf("\n");
    }
    return 0;
}