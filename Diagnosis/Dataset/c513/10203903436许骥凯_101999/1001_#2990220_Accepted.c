#include<stdio.h>

int main(){
    int pro; scanf("%d", &pro);
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(pro--){
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