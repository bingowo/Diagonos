//string\1067.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

ULL ansDP[77]={0,1,1,2,4,7};//pos 0 should be one
ULL howmany(int floor)
{
    if(floor==0)
        return 0;
    if(ansDP[floor]==0){
        ansDP[floor]=howmany(floor-1)+howmany(floor-2)
        +howmany(floor-3);
    }
    return ansDP[floor];
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
        int tem;
        scanf("%d",&tem);
        printf("%llu\n",howmany(tem));
    }
}
