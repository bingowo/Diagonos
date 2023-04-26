#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    long long a;
} list;
int cmp(const void *a,const void *b)
{
    list* t1=(list*)a;
    list* t2=(list*)b;
    if(t1->a<t2->a)
        return 1;
    else
        return -1;
}
unsigned long long min(unsigned long long x,unsigned long long y)
{
    if(x>y)
        return y;
    else
        return x;
}
int main()
{   long long b[100000];
    int n,m,i;
    scanf("%d%d",&n,&m);
    list *t=(list*)malloc(sizeof(list)*n);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&t[i].a);

    }
    qsort(t,n,sizeof(list),cmp);
    unsigned long long maxn=0,ans=0;
        for(int j=1; j<m;j++)
        {
            ans=ans+t[0].a-t[j].a;
        }
    maxn=ans;
    for(int j=m;j<n;j++)
    {
        ans=ans+(t[j-m+1].a-t[j-m].a)*(m-1)+t[j-m+1].a-t[j].a;
        maxn=min(ans,maxn);
    }

    printf("%llu",maxn);
    free(t);
    return 0;
}
