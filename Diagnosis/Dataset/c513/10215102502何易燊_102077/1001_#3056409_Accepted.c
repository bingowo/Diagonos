#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        long long num;
        int base;
        scanf("%lld %d",&num,&base);
        char stack[50] = {}; int m = 0;
        int isminus = num<0?1:0;
        num = labs(num);
        do
        {
            stack[m++] = num%base<10?num%base+'0':num%base-10+'A';
            num /= base;
        } while (num>0);
        if (isminus) printf("-");
        while (m>0)
        {
            printf("%c",stack[--m]);
        }
        printf("\n");
    }
    return 0;
}