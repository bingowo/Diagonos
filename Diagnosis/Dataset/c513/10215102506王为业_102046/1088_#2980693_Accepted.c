//math\1088.c


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
#define MAXLEN 550
long long comb(int n,int m)
{
    if(m==0){
        return 1;
    }else if(m==1){
        return n;
    }else{
        return comb(n,m-1)*(n-m+1)/m;
    }
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
        int n,m;
        scanf("%d%d",&n,&m);
        if(m>n/2)
            m=n-m;
        printf("%lld\n",comb(n,m));//here n and m aren' connected to ones in the program
    }
}

