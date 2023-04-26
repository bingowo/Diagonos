#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    unsigned long long aa=*((unsigned long long*)a);
    unsigned long long bb=*((unsigned long long*)b);
    if(aa>bb) return -1;
    else if(aa<bb) return 1;
    else return 0;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    unsigned long long *a=malloc(sizeof(unsigned long long)*n);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&a[i]);
    }
    qsort(a,n,sizeof(unsigned long long),cmp);
    unsigned long long mid=a[0],re=0;
    for(i=1;i<n-1;i++)
    {
        mid^=a[i];
    }
    if(mid!=a[n-1]) printf("-1");
    else
    {
        for(i=0;i<n-1;i++)
        {
            re+=a[i];
        }
        printf("%llu",re);
    }
    return 0;
}
