#include<stdio.h>

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

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    STRUCT CASE[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&CASE[i].r);
        scanf("%d",&CASE[i].h);
        CASE[i].s1 = r*r;
        CASE[i].s2 = 2*r*h;
    }
    //两个方案比较
    int mark;
    qsort(CASE,n,sizeof(STRUCT),cmp1);
    long long int sum = CASE[0].s1+CASE[0].s2;
    for(int i=0;i<n;i++)
    {
        long long int temp = CASE[i].s1+CASE[i].s2;
        if(temp>sum)
        {
            sum = temp;
            mark = i;
        }
    }
    long long int ans=CASE[0].s1;
    for(int i=0;i<m;i++)
    {
        ans+=CASE[i].s2;
    }
    printf("%lld\n",ans);
    
    
}
