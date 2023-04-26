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
    else return c.a-d.a;
}
int main()
{
    int t,n,i,j;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d\n",&n);
        struct nums s[10000];
        for(j=0;j<n;j++)
        {
            scanf("%lld",&s[j].a);
            s[j].num=0;
            long long d=1;
            for(int m=0;m<64;m++)
            {
                if(s[m].a&d!=0) s[m].num++;
                d=d<<1;
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        int c;
        for(c=0;c<n-1;c++)
        {
            printf("%lld",s[c].a);
        }
        printf("%lld\n",s[c].a);
    }
    return 0;
}