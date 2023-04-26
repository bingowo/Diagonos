#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, frac;
    scanf("%d %d",&num,&frac);
    while (num%3==0&&frac>1) num /= 3, frac /= 3;
    int stack[64] = {}; int m = 0;
    do
    {
        stack[m++] = num%3;
        num /= 3;
    } while (num>0);
    int exp = 0;
    while (frac>1) exp++, frac /= 3;
    for (int i=0;i<m;i++)
    {
        stack[i]++;
        stack[i+1] += stack[i]/3;
        stack[i] %= 3;
        stack[i]--;
        if (stack[i]==-1) stack[i] = 2;
    }
    if (stack[m]) m++;
    for (int i=m-1;i>=0;i--)
    {
        printf("%d",stack[i]);
        if (i==exp&&exp>0) printf(".");
    }
    printf("\n");
    return 0;
}