#include<stdio.h>

int main(){
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int pro; scanf("%d", &pro);
    while(pro--){
        int n, r; scanf("%d%d", &n, &r);
        char res[32] = {0}; int len = 0, flag = 0;
        if (n < 0) flag = 1, n = -n;
        do{
            res[len++] = table[n % r];
            n /= r;
        }while(n);
        if (flag) printf("-");
        for (int i = len - 1; i >= 0; i--) printf("%c", res[i]);
        printf("\n");
    }
    return 0;
}