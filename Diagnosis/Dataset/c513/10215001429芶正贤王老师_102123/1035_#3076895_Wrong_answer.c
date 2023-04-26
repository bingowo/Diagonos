#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    int r;
    int h;
    long long int s1;
    long long int s2;
}STRUCT;

int cmp1(const void*a,const void*b)
{
    STRUCT *x = (STRUCT*)a;
    STRUCT *y = (STRUCT*)b;
    if(x->s2 != y->s2)//s2降序
        return (y->s2 - x->s2);
    else
        return (y->s1 - x->s1);
    
}

int cmp2(const void*a,const void*b)
{
    STRUCT *x = (STRUCT*)a;
    STRUCT *y = (STRUCT*)b;
    if(x->s1 != y->s1)//s1降序
        return (y->s1 - x->s1);
    else
        return (y->s2 - x->s2);
    
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    STRUCT CASE[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&CASE[i].r);
        scanf("%d",&CASE[i].h);
        CASE[i].s1 = CASE[i].r*CASE[i].r;
        CASE[i].s2 = 2*CASE[i].r*CASE[i].h;
    }
    //两个方案比较
    
    qsort(CASE,n,sizeof(STRUCT),cmp1);
    long long int ans1=CASE[0].s1;
    for(int i=0;i<m;i++)
    {
        ans1+=CASE[i].s2;
    }
    
    qsort(CASE,n,sizeof(STRUCT),cmp2);
    long long int sum = CASE[0].s1+CASE[0].s2;
    int mark=0;
    for(int i=0;i<n;i++)
    {
        long long int temp = CASE[i].s1+CASE[i].s2;
        if(temp>sum)
        {
            sum = temp;
            mark = i;//此圆柱在最底部
        }
    }
    
    long long int ans2=sum;
    for(int i=mark+1;i<mark+m;i++)
    {
        ans2+=CASE[i].s2;
    }
    long long int ans;
    if(ans1>ans2)
        ans = ans1;
    else
        ans = ans2;
    printf("%lld\n",ans);
    return 0;
    
}
