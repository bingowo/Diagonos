#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int x=*((int*)a),y=*((int*)b);
    return x-y;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i=0,sum=0;
    while ((scanf("%d",a+i))!=-1) i++;
    qsort(a,n,sizeof(int),cmp);
    for (int j=1;j<n;j+=2)
        sum=sum+(a[j]-a[j-1]);
    printf("%d",sum);
    return 0;
}
