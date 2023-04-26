#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b) ? a : b

struct column
{
    int R;
    int H;
    long long sside;
};

int cmp(const void* p1, const void* p2)
{
    return (((struct column*)p1)->sside > ((struct column*)p2)->sside)?-1:1;
}

int main()
{
    int m,n;
    long long ans=0;
    struct column num[1000];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&num[i].R,&num[i].H);
        num[i].sside = (long long)2*num[i].R*num[i].H;
    }
    for(int i=0;i<n;i++)
    {
        struct column numx[1000]={0};
        int k=0;
        for(int j=0;j<n;j++)
        {
            if( (j!=i) && (num[j].R<=num[i].R) )
                numx[k++]=num[j];
        }
        qsort(numx, k, sizeof(numx[0]), cmp);
        long long area =0;
        if( (k!=0) && (k>m-1) )
        {
            for(int cnt =0;cnt<m-1;cnt++)
                area+=numx[cnt].sside;
        }
        ans=MAX(ans, area+(long long)num[i].R*num[i].R+(long long)num[i].sside);
    }
    printf("%lld",ans);
    return 0;
}