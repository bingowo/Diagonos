#include<stdio.h>
#include<stdlib.h>
struct nums
{
    long long a;
    int num;
};
int cmp(const void *a,const void *b)
{
    struct nums c=*((struct nums *)a);
    struct nums d=*((struct nums *)b);
    if(c.num!=d.num) return d.num-c.num;
    else if(c.a>d.a) return 1;
    else return -1;
}
int main()
{
    int t,i,j;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d\n",&n);
        struct nums s[10000];
        memset(s,0,sizeof(s));
        for(j=0;j<n;j++)
        {
            scanf("%lld",&s[j].a);
            s[j].num=0;
            long long d=1;
            for(int m=0;m<64;m++)
            {
                if(s[j].a&d) s[j].num++;
                d=d<<1;
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int c=0;c<n-1;c++)
        {
            printf("%lld ",s[c].a);
        }
        printf("%lld\n",s[n-1].a);
    }
    return 0;
}