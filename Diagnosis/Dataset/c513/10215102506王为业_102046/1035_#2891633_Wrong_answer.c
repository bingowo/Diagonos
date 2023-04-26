//sort\1035.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL

#define ARRLEN 1010
#define TRUE 1
#define FALSE 0
struct cyl{
    int R,H;
};

struct cyl arr[ARRLEN];
int cmp(struct cyl*x,struct cyl*y)
{
    return x->R>y->R?-1:1;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n,m;
    scanf("%d%d",&n,&m);
    for(int in=0;in<n;++in){
        scanf("%d %d",&arr[in].R,&arr[in].H);
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    long long xmax=0;
    long long x;
    for(int begin=0;begin<=n-m;++begin){
        x=0;
        for(int in=begin;in<begin+m;++in){
            x+=2*arr[in].R*arr[in].H;
        }
        x+=arr[begin].R*arr[begin].R;
        if(x>xmax)xmax=x;
    }
    printf("%lld",xmax);
}
