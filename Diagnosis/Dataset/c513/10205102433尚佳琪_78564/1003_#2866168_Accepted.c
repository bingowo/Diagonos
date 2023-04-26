#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    long long num;
    int cnt;
}X;
int cl(long long n)//这里也应该改成long long
{
    int cnt=0;
    for(int i=0;i<64;i++)
    {
        if(n&1)cnt++;
        n=n>>1;
    }
    return cnt;
}
int cmp(const void *a,const void *b)
{
    X s1=*(X*)a;
    X s2=*(X*)b;
    if(s1.cnt!=s2.cnt)return s2.cnt-s1.cnt;
    else {
       if(s2.num>s1.num)return 0;
       else return 1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        X a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i].num);
            a[i].cnt=cl(a[i].num);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%lld ",a[i].num);
        printf("\n");
    }

    return 0;
}
