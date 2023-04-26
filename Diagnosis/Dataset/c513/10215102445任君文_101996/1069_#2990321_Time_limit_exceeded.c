#include<stdio.h>
#include<stdlib.h>
int yon(int num)
{
    int a[10]={0};
    int n=0,i=0;
    int f=1;
    while(num!=0)
    {
        a[i]=num%10;
        num=num/10;
        n++;
    }
    for(i=0;i<n/2;i++)
    {
        if(a[i]!=a[n-i-1])
        {
            f=0;
            break;
        }
    }
    return f;
}
int hui(int num)
{
    int a[10]={0};
    int n=0,res=0,i=0;
    while(num!=0)
    {
        a[i]=num%10;
        num=num/10;
        n++;
    }
    for(i=0;i<n;i++)
    {
        res=res*10+a[i];
    }
    return res;
}
int main()
{
    int n,m,t;
    scanf("%d",&n);
    while(yon(n)==0)
    {
        m=hui(n);
        n=n+m;
        t++;
    }
    printf("%d %d\n",t,n);
    return 0;
}