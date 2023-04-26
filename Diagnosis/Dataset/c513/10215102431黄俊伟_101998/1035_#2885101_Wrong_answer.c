#include <stdio.h>
#include <stdlib.h>

struct column
{
    int R;
    int H;

};

int cmp(const void* p1, const void* p2)
{
    if(((struct column*)p1)->R != ((struct column*)p2)->R)
        return ((struct column*)p2)->R - ((struct column*)p1)->R;
    else
        return ((struct column*)p2)->H - ((struct column*)p1)->H;
}

int main()
{
    int m,n;
    long long x=0;
    struct column num[1000];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&num[i].R,&num[i].H);
    }
    qsort(num, n, sizeof(num[0]), cmp);
    for(int i=0;i<m;i++)
        x+=2*num[i].H*num[i].R;
    x+=2*num[0].R*num[0].R;
    printf("%d",x);
    return 0;
}