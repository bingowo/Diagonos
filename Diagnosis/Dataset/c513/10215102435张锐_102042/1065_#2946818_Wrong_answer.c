#include <stdio.h>
#include <stdlib.h>
int f(int a,int n,int y)
{
    if(n==1) return a;
    if(n==2) return 0;
    if(n==3) return a;
    if(n==4) return y;
    if(n>=5) return (f(a,n-1,y)+f(a,n-2,y));
}
int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int y=1;
    for(y=1;;y++)
    {
        int sum=0;
        for(int i=1;i<n;i++)
        {
            sum+=f(a,i,y);
        }
        if(sum=m) break;
    }
    int sum=0;
    for(int i=1;i<=x;i++)
    {
        sum+=f(a,i,y);
    }
    printf("%d\n",sum);
    return 0;
}
