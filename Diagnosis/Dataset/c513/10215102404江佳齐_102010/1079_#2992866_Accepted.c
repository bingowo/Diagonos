#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int add1(int s[],int L,int U)
{
    int sum=0;
    for(int i=L;i<=U;i++) sum+=s[i];
    return sum;
}
long long int add2(int s[],int L,int U)
{
    long long int sum=0;
    for(int i=L;i<=U;i++) sum+=s[i];
    return sum;
}
int cmp(const void *a,const void *b)
{
    int d1,d2;
    d1=*((int*)a);
    d2=*((int*)b);
    return d1-d2;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n,m,j;
        scanf("%d %d",&n,&m);//有n个元素，m组LU选择
        int s[1002],k[500001];
        for(j=1;j<=n;j++) scanf("%d",&s[j]);
        int L,U,d=1,h,len=n;
        int ct=n*(n+1)/2;//子集个数
        while(len)
        {
            for(h=1;h<=n-len+1;h++)
            {
                k[d]=add1(s,h,h+len-1);
                d++;
            }
            len--;
        }
        qsort(k+1,ct,sizeof(k[1]),cmp);
        for(j=0;j<m;j++)
        {
            scanf("%d %d",&L,&U);
            printf("%lld\n",add2(k,L,U));
        }
    }
    return 0;
}
