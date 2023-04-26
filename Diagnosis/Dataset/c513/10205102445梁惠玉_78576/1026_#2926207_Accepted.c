#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int* p1=(int*)a;
    int* p2=(int*)b;

    if(*p1>*p2)
    {
        return 1;
    }
    else{
        return -1;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);

    int result=0;
    for(int i=0;i<n/2;i++)
    {
        result+=(a[2*i+1]-a[2*i]);
    }
    printf("%d\n",result);
    return 0;
}
