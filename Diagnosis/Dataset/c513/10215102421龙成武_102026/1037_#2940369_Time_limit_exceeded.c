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
    int i,j,n,m,*mini,minilen;
    long long res,temp;
    POINT *a;
    j=0;
    scanf("%d %d",&n,&m);
    a=(POINT*)malloc(n*sizeof(POINT));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i].value);
    }
    qsort(a,n,sizeof(POINT),compar);
    for(i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            a[i].steplen=a[i+1].value-a[i].value;
        }
        else
            a[i].steplen= 9223372036854775807;      //无穷大，走不出去
    }
    res=9223372036854775807;
    for(i=0;i<=n-m;i++)
    {
        temp=0;
        for(j=1;j<m;j++)
            temp+=a[i+j-1].steplen*j;
        if(temp<res)
            res=temp;
    }
    printf("%lld",res);
    free(a);
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
