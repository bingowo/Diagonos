#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    long long value,steplen;
}POINT;
int compar(const void *p1,const void *p2);
int main()
{
    int i,j,n,m;
    long long res,temp,*d;
    POINT *a;
    j=0;
    scanf("%d %d",&n,&m);
    a=(POINT*)malloc(n*sizeof(POINT));
    d=(long long*)malloc((n-m+1)*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i].value);
    }
    qsort(a,n,sizeof(POINT),compar);
    for(i=0;i<n-1;i++)
    {
        a[i].steplen=a[i+1].value-a[i].value;
    }
    d[0]=(m-1)*a[0+m-1].steplen;
    for(i=0;i<m-1;i++)
    {
        d[0]-=a[i].steplen;
    }
    for(i=0;i<n-m;i++)
    {
        d[i+1]=d[i]-(m-1)*(a[i+m-1].steplen-a[i+m].steplen)+a[i].steplen-a[i+m-1].steplen;
    }
    //从n-m到n-1，有m个元素
    //从0到n-m，有n-m+1个元素
    temp=0;
    for(i=0;i<m-1;i++)
    {
        temp+=(i+1)*a[i].steplen;
    }
    res=temp;
    for(i=0;i<n-m;i++)
    {
        temp+=d[i];
        if(temp<res)
            res=temp;
    }

    printf("%lld",res);
    free(a);
    free(d);
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    POINT *a=(POINT*)p1,*b=(POINT*)p2;
    if(a->value<b->value)
        flag=-1;
    else
        flag=1;
    return flag;
}
//首先，考试的时候不会就双重for循环吧，超时就超时
//齐次，不要抗拒数学表达式，这道题你不用数学符号写一下规律还真难找到规律
//第三，下表混乱时，写个注释提醒自己很有用