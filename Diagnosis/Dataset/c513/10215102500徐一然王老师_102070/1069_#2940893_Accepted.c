#include <stdio.h>

long long int huiwen(long long int a)
{
    int A[20];
    int i;
    for(i=0;a;i++)
    {
        A[i]=a%10;
        a=a/10;
    }
    for(int j=0;j<i;j++)
    {
        a=a*10+A[j];
    }
    return a;
}

int panduan(long long int a)
{
    int A[20];
    int i,i1,flag=0;
    for(i=0;a;i++)
    {
        A[i]=a%10;
        a=a/10;
    }
    i--;
    i1=i;
    for(int j=0;j<=i1/2;j++)
    {
        if(A[j]==A[i])
        {
            i--;
        }
        else
        {flag=1;break;}

    }
    i=0;
    return flag;
}

int main()
{
    long long int x;
    int count=0;
    long long int sum;
    scanf("%lld",&x);
    for(;panduan(x);)
    {
        sum=huiwen(x);
        x=sum+x;
        count++;
    }
    printf("%d %lld",count,x);

}

