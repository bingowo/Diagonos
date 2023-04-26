#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long i,j,k;
    long long temp;
    long long T,N;
    long long num[10000]={0};
    long long n[10000]={0};
    scanf("%lld",&T);
    for(i=0;i<T;i++)
    {
        scanf("%lld",&N);
        for(j=0;j<N;j++)
        {
            scanf("%lld",&num[j]);
        }
        for(j=0;j<N;j++)
        {
            if(num[j]<Min)
                Min=num[j];
        }
        printf("Min=%d\n",Min);
        for(j=0;j<N;j++)
        {
            temp=abs(num[j]);
            while(temp>=10)
            {
                temp=temp/10;
            }
            n[j]=temp;
        }
        for(j=0;j<N-1;j++)
        {
            for(k=0;k<N-1-j;k++)
            {
                if(n[k]<n[k+1])
                {
                    temp=n[k];n[k]=n[k+1];n[k+1]=temp;
                    temp=num[k];num[k]=num[k+1];num[k+1]=temp;
                }
                else if(n[k]==n[k+1])
                {
                    if(num[k]>num[k+1])
                    {
                        temp=n[k];n[k]=n[k+1];n[k+1]=temp;
                        temp=num[k];num[k]=num[k+1];num[k+1]=temp;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<N-1;j++)
        {
            printf("%lld ",num[j]);
            n[j]=0;num[j]=0;
        }
        printf("%lld\n",num[N-1]);
        num[N-1]=0;
        n[N-1]=0;
    }
    return 0;
}