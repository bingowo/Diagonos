#include<stdio.h>
#include<stdlib.h>

int cmpA(const void*a,const void*b)
{return*(int*)a>*(int*)b?1:-1;}

int cmpD(const void*a,const void*b)
{return*(int*)a<*(int*)b?1:-1;}

int main()
{
    char c;scanf("%c",&c);
    int cnt=0,n;
    int p[1000]={0},get[101];
    while((scanf("%d",&n))!=EOF)
    {
        if(p[n]==0)
        {p[n]=1;get[cnt++]=n;}
    }
    if(c=='A') qsort(get,cnt,sizeof(int),cmpA);
    else qsort(get,cnt,sizeof(int),cmpD);
    for(int t=0;t<cnt;t++) printf("%d ",get[t]);

    return 0;
}