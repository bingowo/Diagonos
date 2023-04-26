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
    int R;
    long long surS;
};

struct cyl arr[ARRLEN];
int cmp(struct cyl*x,struct cyl*y)
{
    return x->surS>y->surS?-1:1;
}//why we only need to care about surS?
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n,m;
    scanf("%d%d",&n,&m);
    long long temH;
    for(int in=0;in<n;++in){
        scanf("%d %lld",&arr[in].R,&temH);
        arr[in].surS=2*temH*arr[in].R;
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    long long x=0;
    int Rmax=0;
    for(int in=0;in<m;++in){
        x+=arr[in].surS;
        if(arr[in].R>Rmax)Rmax=arr[in].R;
    }
    x+=Rmax*Rmax;
    printf("%lld",x);
}
