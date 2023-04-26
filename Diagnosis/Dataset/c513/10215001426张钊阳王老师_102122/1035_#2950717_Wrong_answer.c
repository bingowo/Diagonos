#include <stdio.h>
#include <stdlib.h>

struct lum{
        long long r;
        long long h;
        long long k;
        long long jud;
};

int main()
{
    int cmp1(const void *a1,const void *b1);
    int cmp2(const void *a1,const void *b1);
    int n,m;
    long long int sum=0;
    scanf("%d %d",&n,&m);
    struct lum s[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&s[i].r,&s[i].h);
        s[i].jud=s[i].r*s[i].r;
        s[i].k=2*s[i].r*s[i].h;
    }

    //以上是输入半径高度并求出表面积 之后开始排序抽取

    qsort(s,n,sizeof(s[0]),cmp1);
    long long max=s[0].r;
    for(int j=0;j<m;j++)
    {
        sum+=s[j].k;
        if(s[j].r>max) max=s[j].r;
    }
    sum+=max*max;
    printf("%lld",sum);
    return 0;
}


int cmp1(const void *a1,const void *b1)
{
    struct lum a=*(struct lum*)a1;
    struct lum b=*(struct lum*)b1;
    if(b.k!=a.k) return (int)(b.k-a.k);
}


