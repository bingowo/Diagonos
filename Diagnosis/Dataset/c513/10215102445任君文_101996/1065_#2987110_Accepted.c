#include<stdio.h>
int numa(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 0;
    else if(n==3)
        return 1;
    else if(n==4)
        return 1;
    else
        return (numa(n-1)+numa(n-2));
}
int numq(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else if(n==3)
        return 1;
    else if(n==4)
        return 2;
    else
        return (numq(n-1)+numq(n-2));
}
int cusa(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else if(n==3)
        return 2;
    else if(n==4)
        return 2;
    else
        return (cusa(n-1)+numa(n-2));
}
int cusq(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 0;
    else if(n==3)
        return 0;
    else if(n==4)
        return 1;
    else if(n==5)
        return 2;
    else
        return(cusq(n-1)+numq(n-2));
}
int main()
{
    int a,n,m,x;
    int q=0,na=0,nq=0,res=0;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    na=cusa(n-1);
    nq=cusq(n-1);
    q=(m-na*a)/nq;
    na=cusa(x);
    nq=cusq(x);
    res=na*a+nq*q;
    printf("%d\n",res);
    return 0;
}