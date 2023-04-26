#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlen 1000000000


int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        long long int A,B,N;
        scanf("%lld %lld %lld",&A,&B,&N);
        long long int count=1,a=A;
        for(int i=0;i<N;i++)count*=10;
        for(int i=0;i<B-1;i++){
            A%=count;
            A*=a;
        }
        A%=count;
        printf("case #%d:\n",t);
        printf("%0*lld\n",(int)N,A);
    }
    return 0;
}