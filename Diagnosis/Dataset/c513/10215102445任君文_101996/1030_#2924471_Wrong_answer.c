#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,k;
    long long temp;
    int T,N;
    long long num[10000]={0};
    long long n[10000]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%lld",&num[j]);
        }
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
        }
        printf("%lld\n",num[N-1]);
    }
    return 0;
}