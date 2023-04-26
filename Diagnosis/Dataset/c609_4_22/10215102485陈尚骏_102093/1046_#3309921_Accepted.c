#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char c;
    int cnt;
}PR;


int sta(char*s,PR*r)
{
    char prev;
    int cnt=0,rcnt=0;
    for(prev=*s++;*s;++cnt,prev=*s++)
    {
        if(*s!=prev) r[rcnt].c=prev,r[rcnt++].cnt=cnt,cnt=0;
    }
    r[rcnt].c=prev,r[rcnt++].cnt=cnt;
    return rcnt;
}

int aL_char(PR (*f)[100],int n,int*fn)
{
    int i,j;
    for(i=1;i<n;++i)
    {
        if(fn[i]!=fn[0]) return 0;
    }
    for(i=0;i<fn[0];++i)
    {
        for(j=1;j<n;++j)
        {
            if(f[j][i].c!=f[0][i].c) return 0;
        }
    }
    return 1;
}

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n,i,j,ans=0;
    int fn[100000],a[100000];
    char s[101];
    PR f[100000][100];
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        fn[i]=sta((scanf("%s",s),s),f[i]);
    }
    if(aL_char(f,n,fn))
    {
        for(i=0;i<fn[0];++i)
        {
            for(j=0;j<n;++j)
            {
                a[j]=f[j][i].cnt;
            }
            qsort(a,n,sizeof(a[0]),cmp);
            for(j=0;j<n;++j)
            {
                ans+=abs(a[j]-a[n/2]);
            }
        }
        printf("%d\n",ans);
    }
    else printf("-1\n");
    return 0;
}
