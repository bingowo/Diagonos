#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*a,const void*b)
{return *(long long*)a>*(long long*)b;}

void val(int*in,long long*newr,int n)
{
    int i,j,m=0;newr[0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            for(int k=j;k<=j+i-1;k++)
                newr[m]+=in[k-1];
            m++;
            newr[m]=0;
        }
    }
    qsort(newr,m-1,sizeof(long long),cmp);
}

int main()
{
    int T,i;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,m,i,j;
        int in[1000];long long*newr=malloc(sizeof(long long)*1000000);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)scanf("%d",&in[i]);
        val(in,newr,n);
        int L,U;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&L,&U);
            long long sum=0;
            for(j=L-1;j<U;j++)sum+=newr[j];
            printf("%d\n",sum);
        }
    }
}
