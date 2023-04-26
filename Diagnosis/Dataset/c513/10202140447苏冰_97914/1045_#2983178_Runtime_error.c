#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100
typedef struct
{
    char c;
    int cnt;

}PAIR;
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int cal(char* s,PAIR* r)
{
    char *p=s,*q=s;
    int ct=0;int i=0;
    while(*p!='\0')
    {
        while(*p==*q)
        {
            ct++;
            p++;
        }
        r[i].c=*q;r[i++].cnt=ct;
        q=p;ct=0;
    }
    return i;
}
int main()
{
    int n;
    scanf("%d",&n);
    PAIR f[N][100];
    char s[101];
    int a[N];int k=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        a[k++]=cal(s,f[i]);
    }
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[0])
        {
            flag=0;
            break;
        }
    }
    int x=a[0];
    for(int i=0;i<n && flag;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            if(f[i][j].c!=f[0][j].c)
            {
                flag=0;
                break;
            }
        }
    }
    if(flag)
    {
        int ans=0;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[j]=f[j][i].cnt;
            }
            qsort(a,n,sizeof(a[0]),cmp);
            for(int j=0;j<n;j++)
            {
                ans+=abs(a[j]-a[n/2]);
            }
        }
        printf("%d\n",ans);
    }
    else printf("-1\n");
    return 0;
}


