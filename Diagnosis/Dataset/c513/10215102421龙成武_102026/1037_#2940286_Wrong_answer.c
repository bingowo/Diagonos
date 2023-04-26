#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
int main()
{
    int i,j,n,m,*mini,minilen;
    long long *a,res=0,minlen,temp;
    j=0;
    scanf("%d %d",&n,&m);
    mini=(int*)malloc(n*sizeof(int));
    a=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),compar);
    minlen=9223372036854775807;
    for(i=0;i<=n-m;i++)
    {
        temp=a[i+m-1]-a[i];
        if(temp<minlen)
        {
            minlen=temp;
            j=0;
            mini[j++]=i;
        }
        else if(temp==minlen)
        {
            mini[j++]=i;
        }
    }
    minilen=j;
    for(i=0;i<minilen;i++)
    {
        for(j=mini[i];j<mini[i]+m;j++)
        {
            res+=a[mini[i]+m-1]-a[j];
        }
    }
    printf("%lld",res);
    free(a);
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    long long *a=(long long*)p1,*b=(long long*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
