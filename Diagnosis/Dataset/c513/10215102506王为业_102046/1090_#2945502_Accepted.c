//math\1090.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    LL N;
    while(scanf("%lld",&N)!=EOF&&N!=0){
        LL tem_dig=N*log10(N);
        LL result=pow(10,N*log10(N)-tem_dig);
        printf("%lld\n",result);
    }
}
