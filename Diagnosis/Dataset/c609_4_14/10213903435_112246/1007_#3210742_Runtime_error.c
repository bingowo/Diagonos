#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long m=*(long long*)a;
    long long n=*(long long*)b;
    int sign=-1;
    if(m>n)sign=1;
    int cnt_m,cnt_n;
    if(m%2==0)cnt_m=0;else cnt_m=1;
    if(n%2==0)cnt_n=0;else cnt_n=1;
    m=(unsigned long long)m>>1;n=(unsigned long long)n>>1;
    do
    {
        if(m%2==1)cnt_m++;
        m>>=1;

    }while(m>0);
    do
    {
        if(n%2==1)cnt_n++;
        n>>=1;
    }while(n>0);
    return (cnt_m!=cnt_n)?cnt_n-cnt_m:sign;
}
int main()
{
    int T,i=0,j;
    int N;
    scanf("%d",&T);
    long long arr[10][1000];
    int length[10];
    while(i<T)
    {
        scanf("%d",&N);
        length[i]=N;
        j=0;
        while(j<N)
        {
            scanf("%lld",arr[i]+j);
            j++;
        }
        qsort(arr[i],N,sizeof(long long),cmp);
        i++;
    }
    for(i=0;i<T;i++)
    {
       printf("case #%d:\n",i);
       for(j=0;j<length[i];j++)printf("%lld ",arr[i][j]);
       printf("\n");
    }
    return 0;
}
