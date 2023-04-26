//string\1062.c
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

ULL ansDP[51]={1,1,2,4,8};//pos 0 should be one
ULL howmany(int floor)
{
    if(ansDP[floor]==0){
        ansDP[floor]=howmany(floor-1)+howmany(floor-2)
        +howmany(floor-3)+howmany(floor-4);
    }
    return ansDP[floor];
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int N;
    scanf("%d",&N);
    for(int iN=0;iN<N;++iN){
        printf("case #%d\n:",iN);
        int tem;
        scanf("%d",&tem);
        printf("%llu\n",howmany(tem));
    }
}
