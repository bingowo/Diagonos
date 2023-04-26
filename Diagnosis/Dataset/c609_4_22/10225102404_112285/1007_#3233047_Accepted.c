#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    long long i=*(long long*)a,j=*(long long*)b;
    int cnt1=0,cnt2=0;
    while(i)
    {
        i=i&(i-1);
        cnt1++;
    }
    while(j)
    {
        j=j&(j-1);
        cnt2++;
    }
    if(cnt1>cnt2)
    {
        return -1;
    }
    else if(cnt1<cnt2)
    {
        return 1;
    }
    else
    {
        long long i=*(long long*)a,j=*(long long*)b;
        if(i>j)
        {
            return 1;
        }
        else if(i<j)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,t=0;
        long long a[10010];
        scanf("%d",&N);
        while(t<N)
        {
            scanf("%lld",&a[t]);
            t++;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("%lld ",a[j]);
        }
        printf("\n");
    }
    return 0;
}
