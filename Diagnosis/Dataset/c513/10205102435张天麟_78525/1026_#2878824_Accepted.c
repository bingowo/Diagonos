#include<stdio.h>
#include<stdlib.h>
int ab[100001];
int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int*)a;
    s2=(int*)b;
    return *s1-*s2;
}
int main()
{
    int T,n,ans=0,i;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        scanf("%d",&ab[n]);
    }
    qsort(ab,n,sizeof(ab[0]),cmp);
    for(i=0;i<T-1;i+=2)
    {
        ans+=ab[i+1]-ab[i];
    }
    printf("%d",ans);
    return 0;
}