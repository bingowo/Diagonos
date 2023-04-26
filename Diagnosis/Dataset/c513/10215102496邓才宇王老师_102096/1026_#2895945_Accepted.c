#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2)
{
    int* a=p1;
    int* b=p2;
    return *a-*b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int s[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    qsort(s,n,sizeof(int),cmp);
    int j=0;
    long long int ans=0;
    while(j<n)
    {
        ans=ans+s[j+1]-s[j];
        j=j+2;
    }
    printf("%lld",ans);
}
