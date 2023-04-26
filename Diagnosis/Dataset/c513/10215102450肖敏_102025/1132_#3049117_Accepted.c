#include <stdio.h>
int Sum(int n,int r)
{
    int sum=0;
    do {
        sum += n % r;
        n /= r;
    } while (n);
    return sum;
}
int main() {
    int n, r, T, i;
    int a[32];
    char table[] = "0123456789ABCDEF";
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d%d", &n, &r);
        int s=Sum(n,r);
        int j=0;
        do{
            a[j++]=s%r;
            s /= r;
        }while(s);
        printf("case #%d:\n",i);
        while(j > 0)
        {
            printf("%c",table[a[--j]]);
        }
        printf("\n");
    }
    return 0;
}