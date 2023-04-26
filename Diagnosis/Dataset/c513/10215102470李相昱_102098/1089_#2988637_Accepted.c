
#include <stdio.h>
#include <math.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        long long int A,B,N;
        scanf("%lld%lld%lld",&A,&B,&N);
        long long int ret=1;
        for(int j=0;j<B;j++){
            ret = ret*A;
            long long int temp=(long long int)pow(10,N);
            if(ret>=temp ){
                ret = ret%temp;
            }
        }
        long long int p=ret;
        int cnt=0;
        while(p>0){
            p/=10;
            cnt++;
        }
        printf("case #%d:\n",i);
        if(cnt<N){
            int q2=N-cnt;
            for(int q=0;q<q2;q++){
                printf("0");
            }
        }
        if(ret){
            printf("%lld",ret);
        }
        printf("\n");
    }

    return 0;
}
