#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10007
int T,a,b,k,n,m;
int fac[10005];

//关键是每次运算结果都要取余数
//从而使结果不会溢出

//求x的y次方
int solve(int x,int y)
{
    int res=x,ans=1;
    //关键还是利用二进制
    //将次数二进制处理
    //比常规运算更快
    while(y)
    {
        if(y%2)
            ans=ans*res%M; //奇数情况，结果乘底数
        res=res*res%M; //底数平方
        y>>=1; //次数除以2
    }
    return ans;
}

int main()
{
    fac[0]=1;
    for(int i=1;i<=10000;i++)
        fac[i]=fac[i-1]*i%M; //阶乘
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        a%=M;
        b%=M;
        printf("case #%d:\n%d\n",c,
               solve(a,n)*solve(b,m)%M*fac[k]%M*solve(fac[n],M-2)%M*solve(fac[m],M-2)%M);
    }
    return 0;
}
