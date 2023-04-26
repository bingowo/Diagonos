#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    int s1=*(int*)a;
    int s2=*(int*)b;
    return s1-s2;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int ans=0;
    for(int i=0;i<n;i+=2)
    {
        ans+=a[i+1]-a[i];
    }
    printf("%d",ans);
}
