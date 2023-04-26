#include<stdio.h>
#include<stdlib.h>
struct NUM
{
    long long int a;//输入数字
    int num;//1的个数
};
int cmp(const void *a,const void *b)
{
    struct NUM d1,d2;
    d1=*((struct NUM *)a);
    d2=*((struct NUM *)b);
    if(d1.num!=d2.num) return d2.num-d1.num;
    else if(d1.a>d2.a) return 1;
    else return -1;
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int n,c;//数字个数
        scanf("%d\n",&n);
        struct NUM s[10000];
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&s[j].a);
            long long int d=1;
            s[j].num=0;
            for(int m=0;m<64;m++)
            {
                if(s[j].a&d!=0) s[j].num++;
                d=d<<1;
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);//排序数组、个数、sizeof（数组【0】）、cmp
        printf("case #%d:\n",i);
        for(c=0;c<n-1;c++)
        {
            printf("%lld ",s[c].a);
        }
        printf("%lld\n",s[n].a);
    }
    return 0;
}