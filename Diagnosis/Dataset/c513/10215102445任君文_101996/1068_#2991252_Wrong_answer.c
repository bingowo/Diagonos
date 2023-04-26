#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int number(int num)
{
    if (num == 1)
        return 0;
    else if (num == 2)
        return 2;
    else if (num == 3)
        return 6;
    else if (num == 4)
        return 24;
    else
        return (number(num-1)*num);
}
int main()
{
    int n = 0,m=0;
    int res = 0;
    while ((n != -1)&&(m!=-1))
    {
        scanf("%d%d", &n,&m);
        if((m==-1)&&(n==-1))
            break;
        res = number(n-m+1)+1;
        printf("%d\n", res);
    }
    return 0;
}