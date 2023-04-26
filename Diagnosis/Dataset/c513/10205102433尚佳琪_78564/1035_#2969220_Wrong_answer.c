#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int r;
    int h;
    int d;
    int c;
}NODE;
int cmp(const void*a,const void*b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.c!=s2.c)
        return s2.c-s1.c;
    else
        if(s2.d!=s1.d)
            return s2.d-s1.d;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    NODE a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].r,&a[i].h);
        a[i].d=a[i].r*a[i].r;
        a[i].c=2*a[i].r*a[i].h;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int ans=0;
    ans=a[0].r*a[0].r;
    for(int i=0;i<m;i++)
    {
        ans=ans+a[i].r*a[i].h*2;
    }
    printf("%d",ans);
    return 0;
}
