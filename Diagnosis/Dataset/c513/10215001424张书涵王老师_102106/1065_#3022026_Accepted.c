#include <stdio.h>
#include <stdlib.h>

int main()//暴力枚举法
{
    int n,a,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int amount=a;
    if(x==1)
    {
        printf("%d",a);
        return 0;
    }
    if(x==2)
    {
        printf("%d",a);
        return 0;
    }
    int b[21]={0};//每个车站上车的人数
    int c[21]={0};//每个车站下车的人数
    int i;
    b[0]=a;
    for(b[1]=0;b[1]<=m;b[1]++)
    {
        for(i=2;i<(n-1);i++)
        {
            b[i]=b[i-1]+b[i-2];
            c[i]=b[i-1];
            amount=amount+b[i]-c[i];
        }
        if(amount==m)
            break;
        amount=a;
    }
    c[1]=b[1];
    amount=a;
    for(i=2;i<x;i++)
        amount=amount+b[i]-c[i];
    printf("%d",amount);
}