#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int d1,d2;
    d1=*((int*)a),d2=*((int*)b);
    return d1-d2;
}

int main()
{
    int n,num[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    int sum=0;
    for(i=0;i<n;i+=2) sum+=num[i+1]-num[i];
    printf("%d",sum);
    return 0;
}

