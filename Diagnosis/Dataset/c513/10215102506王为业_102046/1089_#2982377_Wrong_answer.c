//math\1089.c


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
        unsigned long long A;
        unsigned long long res=1;
        int B,N;
        scanf("%llu %d %d",&A,&B,&N);
        int left=1;
        for(int iN=0;iN<N;++iN){
            left*=10;
        }
        A%=left;
        while(B!=0){
            if(B&1){
                res*=A;
                res%=left;
            }
            A*=A;
            A%=left;
            B>>=1;
        }
        int len=0;
        ULL tem=res;
        while(tem!=0){
            ++len;
            tem/=10;
        }
        for(int i=0;i<N-len;++i){
            putchar('0');
        }
        if(res!=0)
            printf("%llu\n",res);//there is still
    }

}

