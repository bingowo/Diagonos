#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct SSS
{
    int tall;
    long long int num;
}stu;
int cmp(const void*_a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if((a->tall)!=(b->tall)) return((b->tall)-(a->tall));
    else return ((a->num)>(b->num)?1:-1);
}
int main()
{
    int T,n;
    long long int x;
    scanf("%d",&T);
    stu s[10010];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&x);
            s[j].num=x;
            if(x<0) x=-x;
            while(x>=10)
            {
                x/=10;
            }
            s[j].tall=x;
        }
        qsort(s,n,sizeof(stu),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n-1;j++)
        {
            printf("%lld ",s[j].num);
        }
        printf("%lld\n",s[n-1].num);
    }
    return 0;
}

