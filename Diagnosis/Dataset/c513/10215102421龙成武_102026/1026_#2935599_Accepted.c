#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void *p1,const void *p2);
int main()
{
    int n,*a,i;
    long long res=0;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compar);
    for(i=0;i<n;i+=2)
    {
        res+=llabs(a[i]-a[i+1]);
    }
    printf("%d",res);
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    int *a=(int*)p1,*b=(int*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
