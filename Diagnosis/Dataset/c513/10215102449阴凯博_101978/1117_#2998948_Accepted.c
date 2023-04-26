#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define N 81

long long xx;
long long yy;

unsigned long long Abs(long long a)
{
    return (a>=0)?a:-a;
}

typedef struct
{
    long long x;
    long long y;
    unsigned long long sum
} POINT;

int cmp(const void *a,const void *b)
{
    POINT* pa =(POINT*)a,*pb=(POINT*)b;
    if(pa->sum>pb->sum) return 1;
    if(pa->sum<pb->sum) return -1;
    if(pa->sum==pb->sum)
    {
        if (pa->x>pb->x) return 1;
        if (pa->x<pb->x) return -1;
        if (pa->x==pb->x)
        {
            return (pa->y>pb->y)?1:-1;

        }
    }

}

POINT* input(int n)
{
    int i;
    POINT* a=(POINT*)malloc(n*sizeof(POINT));
    for (i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].sum=(Abs(a[i].x-xx)>=Abs(a[i].y-yy))?Abs(a[i].x-xx):Abs(a[i].y-yy);
    }
    return a;
}


int main()
{

    int n;
    scanf("%lld %lld",&xx,&yy);
    scanf("%d",&n);
    POINT* arr=NULL;
    arr=input(n);
    qsort(arr,n,sizeof(POINT),cmp);

    printf("%lld\n",arr[0].sum);
    printf("%lld %lld\n",arr[0].x,arr[0].y);
    free(arr);
    return 0;
}