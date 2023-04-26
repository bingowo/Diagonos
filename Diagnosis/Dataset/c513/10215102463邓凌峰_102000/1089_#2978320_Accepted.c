#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        long long A,B,N;scanf("%lld%lld%lld",&A,&B,&N);
        long long weight=1;
        for(int j=0;j<N;j++) weight*=10;
        long long ans=A%weight;
        for(int j=1;j<B;j++){
            ans*=A;
            ans%=weight;
        }
        long long tmp=ans,n=0;
        do{
            n++;
            tmp/=10;
        }while(tmp>0);
        printf("case #%d:\n",i);
        if(n<N){
            n=N-n;
            while(n--) printf("0");
        }
        printf("%lld\n",ans);

    }




    return 0;
}
