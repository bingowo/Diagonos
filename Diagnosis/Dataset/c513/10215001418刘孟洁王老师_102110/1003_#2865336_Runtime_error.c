#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 10000
long long int number(long long int a)
{
    long long unsigned b=1;int i=0,k=0;
    while(i<=64)
    {
        if(a&b==0)i++;
        else i++,k++;
        b<<=1;
    }
    return k;
}

int compare(const void*a,const void*b)
{
    long long int pa=*(long long int*)a;
    long long int pb=*(long long int*)b;
    int c=number(pa);
    int d=number(pb);
    if(c>d)return 1;
    else if(c<d)return -1;
    else if(pa>pb)return 1;
    else if(pa<=pb)return -1;
}
void sortcomp(long long int *p,int n)
{
    qsort(p,n,sizeof(long long int),compare);
}
int main()
{
    int i,n,cas,t,w;long long int s[N][N];
    scanf("%d",&n);
    for(t=0;t<n;t++)
    {
        scanf("%d",&cas);
        for(i=0;i<cas;i++)scanf("%lld",&s[t][i]);}
        sortcomp(s,cas);
        for(w=0;w<n;w++)
        {printf("case #%d:\n",w);
        for (i=0; i<n; i++) printf("%lld%c",s[w][i],i=cas-1?'\n':' ');}

return 0;
}
