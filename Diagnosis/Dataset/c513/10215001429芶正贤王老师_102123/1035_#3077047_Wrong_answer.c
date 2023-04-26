#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    long long int r;
    long long int h;
    long long int s1;
    long long int s2;
}STRUCT;

int cmp2(const void*a,const void*b)//侧面积s2排序
{
    STRUCT *x = (STRUCT*)a;
    STRUCT *y = (STRUCT*)b;
    if(x->s2 != y->s2)//s2降序
    {
        if(x->s2 > y->s2)
            return -1;
        else
            return 1;
    }
    else
    {
        if(y->s1 > x->s1)
            return 1;
        else
            return -1;
    }
    
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    STRUCT CASE[1005];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&CASE[i].r);
        scanf("%lld",&CASE[i].h);
        CASE[i].s1 = CASE[i].r*CASE[i].r;
        CASE[i].s2 = 2*CASE[i].r*CASE[i].h;
    }
    //两个方案比较
    
    qsort(CASE,n,sizeof(STRUCT),cmp2);
    long long int ans1=0;
    for(int i=0;i<m;i++)
    {
        ans1+=CASE[i].s2;
    }
    long long int max=CASE[0].s1;
    for(int i=0;i<m;i++)
    {
        if(CASE[i].s1>max)
            max = CASE[i].s1;
    }
    ans1 += max;

    printf("%lld\n",ans1);
    return 0;
    
}