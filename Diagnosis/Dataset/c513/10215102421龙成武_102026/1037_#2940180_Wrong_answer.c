#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
int main()
{
    int i,j,n,m;
    long long *a,res=0;
    scanf("%d %d",&n,&m);
    a=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(int),compar);
    for(i=0;i<m-1;i++)
    {
        res+=a[m]-a[i];
    }
    printf("%lld",res);
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    int*a=(int*)p1,*b=(int*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
