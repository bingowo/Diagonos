//math\1083.c


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
        int N;
        scanf("%d",&N);
        int dim_two=0;
        int dim_five=0;
        for(int i=2;i<=N;++i){
            int tem=i;
            while(tem%2==0){
                ++dim_two;
                tem/=2;
            }
            tem=i;
            while(tem%5==0){
                ++dim_five;
                tem/=5;
            }
        }
        printf("%d\n",dim_five>dim_two?dim_two:dim_five);
    }
}

