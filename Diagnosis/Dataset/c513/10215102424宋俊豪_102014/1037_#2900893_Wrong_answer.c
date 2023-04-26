#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    long long a;
}list;
int cmp(const void *a,const void *b)
{
    list* t1=(list*)a;
    list* t2=(list*)b;
    if(t1->a<t2->a)
        return 1;
    else
        return -1;
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
     list *t=(list*)malloc(sizeof(list)*n);
      for(i=0; i<n; i++)
    {
        scanf("%lld",&t[i].a);
    }
    qsort(t,n,sizeof(list),cmp);
    unsigned long long ans=0;
    for(i=n-m+1;i<n;i++)
    {
        ans=ans+t[n-m].a-t[i].a;
    }
    printf("%llu",ans);
    free(t);
    return 0;
}
