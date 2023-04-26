#include <stdio.h>
#include <stdlib.h>
int f(long long n)
{
    int *p;
    int i;
    p=(int *)malloc(sizeof(int)*64);
    if(n<0)
    {
        *p=1;
        n=-n;
    }
    else if(n>0) *p=0;
    for(i=63;i>=1;i--)
    {
        *(p+i)=n%2;
        n=n/2;
    }
    if(*p==1)
    {
        for(i=1;i<=63;i++)
        {
            if(*(p+i)==1) *(p+i)=0;
            else *(p+i)=1;
        }
    }
    if(*p==1)
    {
        if(*(p+63)==0) *(p+63)=1;
        else if(*(p+63)==1)
        {
            for(i=63;i>0;i--)
            {
                if(*(p+63)+1==2)
                {
                    *(p+63)=0;
                    *(p+62)+=1;
                }
                else if(i>0&&*(p+i)==2)
                {
                    *(p+i)=0;
                    *(p+i-1)+=1;
                }
            }
        }
    }
    int cnt=0;
    for(i=0;i<=63;i++)
    {
        if(*(p+i)==1)
            cnt=cnt+1;
    }
    return cnt;
}
int main()
{
    int T;scanf("%d",&T);
    long long mi;
    for(int i=0;i<T;i++)
    {

        int N;scanf("%d",&N);
        long long a[N];
        for(int j=0;j<N;j++)
            scanf("%lld",&a[j]);
        printf("case #%d:\n",i);
        if(N==1)
            printf("%lld",a[0]);
        else{
            for(int j=N-2;j>=0;j--)
            {
                for(int k=0;k<=j;k++)
                {
                    if(f(a[k])<f(a[k+1])||f(a[k])==f(a[k+1])&&a[k]>a[k+1])
                    {
                        mi=a[k];a[k]=a[k+1];a[k+1]=mi;
                    }
                }
            }
            for(int j=0;j<N;j++)
            {
                printf("%lld ",a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
