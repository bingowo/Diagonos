#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int res[501]={0};

int cmp(const void* a,const void* b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    if(res[x]==res[y] && res[x]==0)
    {
        return x-y;
    }
    else if(res[x]==0)
    {
        return 1;
    }
    else if(res[y]==0)
    {
        return -1;
    }
    else
    {
        return res[x]-res[y];
    }
}

int main()
{
    int m,n;
    int a[1000],b[1000];
    int cnt=1;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        res[a[i]]=cnt;
        cnt++;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    qsort(b,n,sizeof(b[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
}
