#include<stdio.h>

int main(){
    int pro; scanf("%d", &pro);
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i != pro; i++){
        int n, r; scanf("%d%d", &n, &r);
        char res[32] = {0}; int len = 0;
        int flag = 0;
        if (n < 0) n = -n, flag =  1;
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