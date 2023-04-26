#include<stdio.h>

void transform(int num, int fac){
    char nums[50];
    int i = 0, flag= 0;
    if (num < 0) {flag = 1; num = -num;}
    while(num){
        int res = num % fac;
        if (res >= 10)
            nums[i++] = res - 10 + 'A';
        else 
            nums[i++] = res + '0';
        num /= fac;
    }
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
    return 0;
}


