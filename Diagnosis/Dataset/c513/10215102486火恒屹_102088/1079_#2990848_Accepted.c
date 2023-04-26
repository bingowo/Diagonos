#include <stdio.h>
#include <stdlib.h>

#define N 1002
long long num[N]={0};
long long res[N*(N+1)/2]={0};
int n;
int k=1;
void initial()
{
    for(int i=0;i<N*(N+1)/2;i++)
        res[i]=0;
    k=1;
}

int cmp(const void*a,const void*b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    return (x-y)>0? 1:-1;
}
void jump(int p)
{
    res[k]=res[k]+num[p];
    k++;
    if(p==n) return;
    else {res[k]=res[k-1];jump(p+1);}

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        initial();
        printf("case #%d:\n",i);
        int m;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;j++)
            scanf("%lld",&num[j]);
        for(int j=1;j<=n;j++)
            jump(j);
        qsort(res,n*(n+1)/2+1,sizeof(long long),cmp);
        for(int j=0;j<m;j++)
        {
            int start,end;
            long long sum=0;
            scanf("%d %d",&start,&end);
            for(int x=start;x<=end;x++)
                sum=sum+res[x];
            printf("%lld\n",sum);
        }
    }
    return 0;
}
