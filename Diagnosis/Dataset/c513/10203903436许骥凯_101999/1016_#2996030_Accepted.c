#include<stdio.h>
int main(){
    int n, r; scanf("%d %d", &n, &r);
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char res[30] = {0}; int rlen = 0;
    do{
        int temp = n % r;        
        n /= r;
        if (temp < 0) temp -= r, n++;
        res[rlen++] = table[temp];
    }while(n);
    for (int i = rlen - 1; i >= 0; i--) printf("%c", res[i]);
    printf("\n");
    return 0;
}