#include<stdio.h>
void transform(int num, int fac){
    char table[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i = 0, flag = 0;
    if (num < 0) {flag = 1; num = -num;}
    char nums[32];
    do{
        nums[i++] = table[num%fac];
        num /= fac;
    }while(num);
    if (flag) printf("-");
    while (i >= 0)
        printf("%c", nums[--i]);
    printf("\n");
}

int main(){
    int n, num, fac;
    scanf("%d", &n);
    for (int i = 0; i != n && scanf("%d%d", &num, &fac); i++)
        transform(num, fac);
}