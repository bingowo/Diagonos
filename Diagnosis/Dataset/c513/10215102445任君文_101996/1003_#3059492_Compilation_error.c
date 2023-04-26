#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10000
int main()
{
    int T,N;
    int i,j,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        unsigned long temp=0,
        long num[M]={0},t[M]={0};
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%ld",&num[j]);
            temp=(unsigned long)num[j];
            while(temp!=0)
            {
                t[j]=t[j]+(temp&1);
                temp=temp>>1;
            }
        }
        for(j=N-1;j>0;j--)
        {
            for(k=0;k<j;k++)
            {
                if(t[k]<t[k+1])
                {
                    swap(t[k],t[k+1]);
                    swap(num[k],num[k+1]);
                }
                else if(t[k]==t[k+1])
                {
                    if(num[k]>num[k+1])
                    {
                        swap(t[k],t[k+1]);
                        swap(num[k],num[k+1]);
                    }
                }
            }
        }
        printf("case #%d:\n",i);
    }
    return 0;
}