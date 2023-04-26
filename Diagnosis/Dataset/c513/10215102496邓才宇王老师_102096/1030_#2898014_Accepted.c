#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int q;
    int max;
}ME;
int change(long long int q)
{
    long long int m=q;
    if(m<0) m=-m;
    while(m/10) m=m/10;
    int w=m;
    return w;
}
int cmp(const void *p1,const void *p2)
{
    ME* a=p1;
    ME* b=p2;
    if((*a).max>(*b).max) return -1;
    else if((*a).max<(*b).max) return 1;
    else
    {
        if((*a).q>(*b).q) return 1;
        else if((*a).q<(*b).q) return -1;
        else return 0;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        ME s[10000];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&s[j].q);
            s[j].max=change(s[j].q);
        }
        qsort(s,N,sizeof(ME),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {
            printf("%lld ",s[k].q);
        }
        printf("\n");
    }

}
