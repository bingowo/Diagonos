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
    long long R,H;
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
    for(int in=0;in<n;++in){
        scanf("%lld %lld",&arr[in].R,&arr[in].H);
        arr[in].surS=2*arr[in].H*arr[in].R;
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    long long xmax=0;
    for(int it=0;it<n;++it){//all kinds of R*R
        long long x=arr[it].surS+arr[it].R*arr[it].R;
        int num=1;//dimian
        for(int i=0;i<n&&num!=m;++i){
            if(i!=it){
                x+=arr[i].surS;
                ++num;
            }
        }
        if(num==m&&x>xmax){
            xmax=x;
        }
    }
    printf("%lld",xmax);
}
