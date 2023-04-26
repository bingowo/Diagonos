#include <stdio.h>
#include <stdlib.h>

long long fact(long long n){
    long long res = 1;
    while(n>0){
        res*=n;
        n--;
    }
    return res;
}

int main()
{

    //printf("%d\n",fact(5));
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int n = 0,m = 0;
        scanf("%d%d",&n,&m);
        long long nFact = fact(n),mFact = fact(m),nMinusMFact = fact(n-m);
        long long res = (nFact/mFact)/nMinusMFact;
        //printf("hhh %lld %lld %lld\n",nFact,mFact,nMinusMFact);

        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}
