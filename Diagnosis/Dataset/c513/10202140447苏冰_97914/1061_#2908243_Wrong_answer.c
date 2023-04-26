#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <limits.h>
typedef struct SSS
{
    char m[20];
    int x;
}sss;
int cmp(const void* p,const void* q)
{
    sss* a=(sss*)p;
    sss* b=(sss*)q;
    if((a->x)!=(b->x)) return ((a->x)>(b->x)?1:-1);
    else return strcmp(a->m,b->m);
}
int main()
{
    int n;
    scanf("%d",&n);
    sss s[10010];
    int a[130];
    for(int i=0;i<n;i++)
    {
        memset(a,-1,sizeof(a));
        scanf("%s",s[i].m);
        int r=0;
        a[s[i].m[0]]=1;
        for(int j=1;j<strlen(s[i].m);j++)
        {
            if(a[s[i].m[j]]==-1)
            {
                a[s[i].m[j]]=r;
                if(r==0) r=2;
                else r++;
            }
        }
        int cnt=0;
        for(int j=0;j<strlen(s[i].m);j++)
        {
            cnt=cnt*r+a[s[i].m[j]];
        }
        s[i].x=cnt;
    }
    qsort(s,n,sizeof(sss),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",s[i].m);
    }
    return 0;
}
