#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int f(int m,int n) //m为连续的1，n为总位数
{
    if(m>n) return 0;
    else if(m==n) return 1;
    //else f(m,n+1)=2*f(m,n)+pow(2,n-m-1)-f(m,n-m-1);
    else return 2*f(m,n-1)+pow(2,n-m-1)-f(m,n-m-1);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=-1&&m!=-1)
    {
        int ans=f(m,n);
        printf("%d\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
