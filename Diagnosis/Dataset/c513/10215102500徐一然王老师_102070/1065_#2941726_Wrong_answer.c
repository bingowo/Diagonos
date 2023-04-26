#include <stdio.h>

long long int A[100]={0};
long long int B[100]={0,0,1};

long long int F(int x,int a)
{
    if(A[x]!=0)
    {
        return A[x];
    }
    if(x==0)
    {
        return 0;
    }
    else if(x==1)
    {
        return A[x]=a;
    }
    else if(x==2)
    {
        return A[x]=0;
    }
    else
    {
        return A[x]=F(x-1,a)+F(x-2,a);
    }
}


int Fxi(int x)
{
    if(B[x]!=0)
    {
        return B[x];
    }
    if(x==0||x==1)
    {
        return 0;
    }
    else if(x==2)
    {
        return 1;
    }
    else if(x==2)
    {
        return B[x]=1;
    }
    else
    {
        return B[x]=Fxi(x-1)+Fxi(x-2);
    }
}

int main()
{
    int a,n,x,k;
    long long int m;
    scanf("%d %d %lld %d",&a,&n,&m,&x);
    k=(m-Fxi(n-2)*a-a)/(Fxi(n-1)-1);
    printf("%d\n",k);
    printf("%lld",Fxi(x-1)*a+Fxi(x)*k+a-k);
}
