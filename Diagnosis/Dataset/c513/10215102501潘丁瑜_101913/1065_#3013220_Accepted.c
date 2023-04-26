#include <stdio.h>
#include <stdlib.h>
int count=0;
int tcount=0;
struct car
{
    int up;
    int down;
    int sum;
}c[21];
//递归求出最后一次上车的人数
//设第二站上车的人数为1，根据这个求出最后一次上车的a与t的系数
int up(int n,int a)
{
    //int i = n;
    if(n==2)
    {
        tcount++;
        return 1;
    }

    else if(n==1)
    {
        count++;
        return a;
    }

    else
    {
        return (up(n-1,a)+up(n-2,a));
    }
}
int subway(int a,int n,int m,int x)
{
    int i;
    c[1].up=a;
    c[1].down=0;
    c[1].sum=a;

    int t;
    up(n-1,a);
    t=(m-a*(1+count))/(tcount-1);
    c[2].up=t;
    c[2].down=t;
    c[2].sum=a;

    for(i=3;i<=n;i++)
    {
        c[i].up=c[i-1].up+c[i-2].up;
        c[i].down=c[i-1].up;
        c[i].sum=c[i-1].sum+c[i].up-c[i].down;
    }
    return c[x].sum;
}
int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    printf("%d",subway(a,n,m,x));
    return 0;
}