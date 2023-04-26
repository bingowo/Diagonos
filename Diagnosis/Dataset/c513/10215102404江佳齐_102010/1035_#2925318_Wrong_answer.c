#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct SSS
{
    long long int R;
    long long int H;
    long long int SC; //侧面积
    long long int SS; //上表面积
    long long int sum;
}s[1000];

int cmp(const void *a,const void *b)
{
    struct SSS s1,s2;
    s1=*((struct SSS*)a);
    s2=*((struct SSS*)b);
    return s2.sum-s1.sum;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld\n",&s[i].R,&s[i].H);
        s[i].SC=2*s[i].R*s[i].H;
        s[i].SS=s[i].R*s[i].R;
        s[i].sum=s[i].SC+s[i].SS;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    long long max=0;//最大的上半径
    long long sum_min=LLONG_MAX;//最小侧面积
    for(int i=0;i<m;i++)
    {
        if(max<s[i].R) max=s[i].R;
        if(sum_min>s[i].SC) sum_min=s[i].SC;
    }
    long long temp=0;
    for(int i=m;i<n;i++)
    {
        if((s[i].sum>sum_min+max*max)&&(s[i].R>max)&&(s[i].sum>temp))
            temp=s[i].sum;
    }
    long long all=0;
    for(int i=0;i<m;i++) all+=s[i].SC;
    if(temp)
    {
        all-=sum_min;
        all+=temp;
    }
    else all+=max*max;
    printf("%lld\n",all);
    return 0;
}
