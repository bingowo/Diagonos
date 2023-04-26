#include <stdio.h>
#include <stdlib.h>


int cmp(const void*a,const void*b)
{
    long long aa=*((long long*)a);
    long long bb=*((long long*)b);
    if(aa>=bb) return 1;
    else return -1;

}

int main()
{
    int n,i;
    scanf("%d",&n);
    long long *x=(long long*)malloc(sizeof(long long)*n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x[i]);
    }
    qsort(x,n,sizeof(long long),cmp);
    long long re=0;
    for(i=0;i<n;i+=2)
    {
        re+=(x[i+1]-x[i]);
    }
    printf("%lld",re);
    return 0;
}
