#include<stdio.h>
#include<stdlib.h>
struct NUM
{
    long long a;
    int num;
};
int cmp(const void *a,const void *b)
{
    struct NUM a1,b1;
    a1=*((struct NUM *)a);
    b1=*((struct NUM *)b);
    if(a1!=b1) return b1.num-a1.num;
    else if(a1.a>b1.a) return 1;
    else return -1;
}
int main(void)
{
    int t;
    scanf("%d\n",&t);
    int i=0,j;
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d\n",&n);
        struct NUM s[10000];
        for(j=0;j<n;j++)
        {
            scanf("%lld",&s[j].a);
            s[j].num=0;
            int d=1;
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