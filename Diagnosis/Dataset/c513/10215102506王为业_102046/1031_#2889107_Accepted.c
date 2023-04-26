//sort\1031.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define ARRLEN 1010
#define TRUE 1
#define FALSE 0

int Aarr[ARRLEN];
int Barr[ARRLEN];
int ascmp(int *x,int*y)
{
    return *x-*y;
}
int decmp(int *x,int*y)
{
    return *y-*x;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int n;
        scanf("%d",&n);
        for(int in=0;in<n;++in){
            scanf("%d",&Aarr[in]);
        }
        for(int in=0;in<n;++in){
            scanf("%d",&Barr[in]);
        }
        qsort(Aarr,n,sizeof(Aarr[0]),ascmp);
        qsort(Barr,n,sizeof(Barr[0]),decmp);
        int sum=0;
        for(int in=0;in<n;++in){
            sum+=Aarr[in]*Barr[in];
        }
        printf("%d\n",sum);
    }
}
