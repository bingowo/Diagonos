#include <stdio.h>
#include <stdlib.h>

int cal(int num,int *count);

int
main()
{
    int num;
    int res;
    int count=0;
    int *pcount = &count;
    
    scanf("%d",&num);
    res = cal(num, pcount);
    printf("%d %d\n",count,res);
    
    return 0;
}

int
cal(int num,int *count)
{
    int n=num;
    int m=0;
    int temp;
    
    while (num != 0)
    {
        temp = num%10;
        m = m*10 + temp;
        num /= 10;
    }
    
    if (n == m)
    {
        return m;
    }
    else
    {
        (*count)++;
        return cal(n+m, count);
    }
}