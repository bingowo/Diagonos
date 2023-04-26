#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[1001];

int cmp(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    if(s[x]!=s[y]) return s[x]-s[y];
    else return x-y;
}

int main()
{
    for(int i=0;i<1001;i++)
        s[i]=500;
    int m,n,a[500],b[500];
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        int x=a[i];
        s[x]=i;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    qsort(b,n,sizeof(b[0]),cmp);
    for(int i=0;i<n-1;i++)
        printf("%d ",b[i]);
    printf("%d\n",b[n-1]);
    return 0;
}
